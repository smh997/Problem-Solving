#include <bits/stdc++.h>
using namespace std;

// Finding Connected Components

// O(V + E)

int n, cc = 0;
vector<int> adj[103];
bool vis[103];
int id[103], ccsize[103];

void dfs(int u){
    vis[u] = true;
    id[u] = cc;
    ccsize[cc]++;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    // read the graph
    fill_n(vis, n, false);
    for(int u = 0; u < n; u++)
        if(!vis[u])
            dfs(u), cc++;
}
