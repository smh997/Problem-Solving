#include <bits/stdc++.h>
using namespace std;

// Topological Sort

// O(V + E)

#define MAX_N 1000003
#define UNVISITED 0
#define EXPLORED 1
#define VISITED 2

vector<int> adj[MAX_N];
int visited[MAX_N];
int parent[MAX_N];
int n, m, a, b;
bool res = true;
vector<int> resv;

void dfs(int u){
    visited[u] = EXPLORED;
    for(auto v : adj[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
        }
        else if(visited[v] == EXPLORED) // check cycle (DAG)
            res = false;
    }
    visited[u] = VISITED;
    resv.push_back(u);
}

int main(){
    // read the graph
    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs(i);
    if(!res)
        cout << "IMPOSSIBLE" << endl;
    else
        for(int i = resv.size() - 1; i >= 0; i--)
            cout << resv[i] << endl;
}

