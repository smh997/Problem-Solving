#include <bits/stdc++.h>
using namespace std;

// Edmond Karp's Network Flow

// O(V * E ^ 2)

const int maxn = 503;
const int inf = INT_MAX;

// s: source, t: sink, c: capacity
int n, m, s, t, c[maxn][maxn], flow[maxn][maxn], par[maxn];
vector<int> adj[maxn];

int augment(){
    fill_n(par, n, -1);
    par[s] = -2;
    queue<pair<int, int>> bfs;
    bfs.push({s, inf});
    while(!bfs.empty()){
        int u = bfs.front().first, f = bfs.front().second;
        bfs.pop();
        if(u == t)
            return f;
        for(int v : adj[u])
            if(par[v] == -1 && c[u][v] - flow[u][v] > 0)
                par[v] = u, bfs.push({v, min(f, c[u][v] - flow[u][v])});
    }
    return 0;
}

int max_flow(){
    int ans = 0;
    while(1){
        int f = augment();
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
vector<int> sCut, tCut;

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v] && c[u][v] - flow[u][v] > 0)
            dfs(v);
}


int main(){
	// read the graph
    cout << max_flow() << endl;
    dfs(s);
    for(int i = 0; i < n; i++){
        if(vis[i])
            sCut.push_back(i);
        else
            tCut.push_back(i);
    }
}