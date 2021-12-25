/*
 * https://open.kattis.com/problems/mincut
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

// Edmond Karp's Network Flow
// O(V * E ^ 2)

const int maxn = 503;
const long long int inf = LLONG_MAX;

// s: source, t: sink, c: capacity
long long int n, m, s, t, c[maxn][maxn], flow[maxn][maxn], par[maxn];
vector<long long int> adj[maxn];

long long int augment(){
    fill_n(par, n, -1);
    par[s] = -2;
    queue<pair<long long int, long long int>> bfs;
    bfs.push({s, inf});
    while(!bfs.empty()){
        long long int u = bfs.front().first, f = bfs.front().second;
        bfs.pop();
        if(u == t)
            return f;
        for(long long int v : adj[u])
            if(par[v] == -1 && c[u][v] - flow[u][v] > 0)
                par[v] = u, bfs.push({v, min(f, c[u][v] - flow[u][v])});
    }
    return 0;
}

long long int max_flow(){
    long long int ans = 0;
    while(1){
        long long int f = augment();
        if(!f)
            break;
        ans += f;
        int it = t;
        while(it != s){
            flow[par[it]][it] += f;
            flow[it][par[it]] -= f;
            it = par[it];
        }
    }
    return ans;
}

// For Minimum Cut Problem:

bool vis[maxn];
vector<long long int> sCut, tCut;

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v] && c[u][v] - flow[u][v] > 0)
            dfs(v);
}


int main(){    
    long long int u, v, w;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        c[u][v] = w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    max_flow();
    dfs(s);
    for(int i = 0; i < n; i++){
        if(vis[i])
            sCut.push_back(i);
        else
            tCut.push_back(i);
    }
    cout << sCut.size() << endl;
    for(auto res: sCut){
        cout << res << endl;
    }
}
