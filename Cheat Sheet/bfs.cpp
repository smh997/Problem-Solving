#include <bits/stdc++.h>
using namespace std;

// SSSP, BFS

// O(V + E)

#define inf INT_MAX

int n, src;
vector<int> adj[103];
int dis[103];
queue<int> bfs;

int main(){
    // read the graph
    fill_n(dis, n, inf);
    dis[src] = 0;
    bfs.push(src);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int v : adj[u])
            if(dis[v] == inf)
                dis[v] = dis[u] + 1, bfs.push(v);
    }
}