#include <bits/stdc++.h>
using namespace std;

// Cut Vertices/Bridges

// O(V + E)

const int maxn = 103;

int v, e;
vector<int> adjs[maxn];
int vis[maxn]; // 0 is for UNVISITED, 1 is for EXPLORED and 2 is for VISITED
int dfs_low[maxn], dfs_num[maxn];
int par[maxn];
int cnt = 0;

set<int> articulation_points;
set<pair<int, int>> bridges;

void dfs(int u){
    vis[u] = 1;
    dfs_low[u] = dfs_num[u] = cnt++;
    for(int v : adjs[u]){
        if(!vis[v]){
            par[v] = u;
            dfs(v);
            if(dfs_low[v] >= dfs_num[u])
                articulation_points.insert(u);
            if(dfs_low[v] > dfs_num[u])
                bridges.insert({u, v});
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != par[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
    vis[u] = 2;
}

int main(){
    // read the graph
    dfs(0);
    if(adjs[0].size() == 1) // root is not ap if it has at most one child
        articulation_points.erase(0);
    // print aps or bridges
}