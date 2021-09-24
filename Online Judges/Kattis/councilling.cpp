/*
 * https://open.kattis.com/problems/councilling
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

// Councilling

const int maxn = 10003;
const int inf = INT_MAX;

int n, party[maxn];
string names[maxn];
vector<int> club[maxn];

int p = 0;
string parties[maxn];
map<string, int> pid;

int gpid(string name){
    if(pid.find(name) != pid.end())
        return pid[name];
    parties[p] = name;
    return pid[name] = p++;
}

int c = 0;
string clubs[maxn];
map<string, int> cid;

int gcid(string name){
    if(cid.find(name) != cid.end())
        return cid[name];
    clubs[c] = name;
    return cid[name] = c++;
}

int d;
string s;

// source: 0, clubs: [1, c], people: [c+1, c+n], parties: [c+n+1, c+n+p], sink: c+n+p+1

int v, capa[maxn][maxn], flow[maxn][maxn], par[maxn];
vector<int> adj[maxn];

int augment(){
    fill_n(par, v, -1);
    par[0] = -2;
    queue<pair<int, int>> bfs;
    bfs.push({0, inf});
    while(!bfs.empty()){
        int u = bfs.front().first, f = bfs.front().second;
        bfs.pop();
        if(u == c + n + p + 1)
            return f;
        for(int v : adj[u])
            if(par[v] == -1 && capa[u][v] - flow[u][v] > 0)
                par[v] = u, bfs.push({v, min(f, capa[u][v] - flow[u][v])});
    }
    return 0;
}

int maxflow(){
    int ans = 0;
    while(1){
        int mf = augment();
        if(!mf)
            break;
        ans += mf;
        int it = c + n + p + 1;
        while(it){
            flow[par[it]][it] += mf;
            flow[it][par[it]] -= mf;
            it = par[it];
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        p = 0, pid.clear(), c = 0, cid.clear();
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> names[i] >> s >> d;
            party[i] = gpid(s);
            club[i].clear();
            while(d--)
                cin >> s, club[i].push_back(gcid(s));
        }
        v = c + n + p + 2;
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++)
                capa[i][j] = flow[i][j] = 0;
        for(int i = 0; i < v; i++)
            adj[i].clear();
        for(int i = 0; i < c; i++)
            adj[0].push_back(1 + i), adj[1 + i].push_back(0), capa[0][i + 1] = 1;
        for(int i = 0; i < p; i++)
            adj[c + n + 1 + i].push_back(c + n + p + 1), adj[c + n + p + 1].push_back(c + n + 1 + i), capa[c + n + 1 + i][c + n + p + 1] = c ? (c / 2 - !(c % 2)) : 0;
        for(int i = 0; i < n; i++){
            adj[c + 1 + i].push_back(c + n + 1 + party[i]), adj[c + n + 1 + party[i]].push_back(c + 1 + i), capa[c + 1 + i][c + n + 1 + party[i]] = 1;
            for(int j : club[i])
                adj[1 + j].push_back(c + 1 + i), adj[c + 1 + i].push_back(1 + j), capa[1 + j][c + 1 + i] = 1;
        }
        int ans = maxflow();
        if(ans != c)
            cout << "Impossible." << endl;
        else{
            for(int j = 0; j < n; j++)
                for(int i = 0; i < c; i++)
                    if(flow[1 + i][c + 1 + j] == 1)
                        cout << names[j] << " " << clubs[i] << endl;
        }
        cout << endl;
    }       
}