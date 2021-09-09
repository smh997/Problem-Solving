#include <bits/stdc++.h>
using namespace std;

// Tree

// Diameter = Longest Path of a Tree

// O(V)

#define MAX_N 100003

int n;
vector<int> adj[MAX_N];

int diameter, ind; // ind is start of longest path (farest node from root)

void dfs(int u, int p, int h){
    if(diameter < h)
        diameter = h, ind = u;
    for(auto v : adj[u])
        if(v != p)
            dfs(v, u, h + 1);
}

int par[MAX_N], ind2; // ind2 is end of longest path (farest node from ind)

void dfs2(int u, int h){
    if(diameter < h)
        diameter = h, ind2 = u;    
    for(auto v : adj[u])
        if(v != par[u])
            par[v] = u, dfs2(v, h + 1);
}

vector<int> path;

int main(){
    // read the graph
    diameter = -1;
    dfs(0, -1, 0);
    diameter = -1;
    dfs2(ind, 0);
    cout << diameter << endl;
    int it = ind2;
    while(it != -1)
        path.push_back(it), it = par[it];
    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}