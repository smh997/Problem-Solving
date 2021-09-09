#include <bits/stdc++.h>
using namespace std;

// Graph Properties Check

// DFS Spanning Tree

// O(V + E)

const int maxn = 50003;

int n;
vector<int> adj[maxn];
int vis[maxn]; // 0 is for UNVISITED, 1 is for EXPLORED and 2 is for VISITED
int par[maxn];
bool cycle = false;

set<pair<int, int>> tree_edge, back_edge, cross_edge;

void dfs(int u){
    vis[u] = 1;
    for(int v : adj[u]){
        if(!vis[v]){
            tree_edge.insert({u, v});
            par[v] = u, dfs(v);
        }
        else if(par[u] != v){ // Not two way edge!
            if(vis[v] == 1)
                cycle = true, back_edge.insert({u, v});
            else // vis[v] == 2
                cross_edge.insert({u, v});
        }
    }
    vis[u] = 2;
}

int main(){
    // read the graph
    for(int i = 0; i < n; i++)
        if(!vis[i])
            dfs(i);
    // print edges
}