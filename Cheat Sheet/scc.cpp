#include <bits/stdc++.h>
using namespace std;

// Finding SCCs

// Tarjan's Algorithm

// O(V + E)

#define MAX_N 100003

int n, m, nums = 1, scc = 0;
int dfs_low[MAX_N], dfs_num[MAX_N];
int compo[MAX_N];
int compoSize[MAX_N];
vector<int> adj[MAX_N];
vector<int> s;
int id[MAX_N];
bool visited[MAX_N];

void dfs(int u){
    dfs_num[u] = dfs_low[u] = nums++;
    s.push_back(u);
    visited[u] = true;
    for(auto v: adj[u]){
        if(!dfs_num[v])
            dfs(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        scc++;
        while(true){
            int w = s.back();
            s.pop_back();
            visited[w] = false;
            compo[w] = scc;
            id[w] = compoSize[scc]++;
            if(w == u)
                break;
        }
    }
}

int main(){
    // read the graph
    for (int i = 0; i < n; i++)
        if(!dfs_num[i])
            dfs(i);
}
