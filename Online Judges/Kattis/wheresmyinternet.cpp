/*
 * https://open.kattis.com/problems/wheresmyinternet
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(200003);
int n, m, a, b;
bool visited[200003];

void dfs(int u){
    visited[u] = true;
    int v;
    for (int i = 0; i < adj[u].size(); ++i) {
        v = adj[u][i];
        if(!visited[v])
            dfs(v);
    }
}

int main()
{
    fill_n(visited, 200003, false);
    cin>>n>>m;
    visited[1] = true;
    for (int i = 0; i < m; ++i) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    bool ans = false;
    for (int i = 2; i <= n; ++i) {
        if(!visited[i]){
            cout<<i<<endl;
            ans = true;
        }
    }
    if(!ans)
        cout<<"Connected"<<endl;
    return 0;
}

