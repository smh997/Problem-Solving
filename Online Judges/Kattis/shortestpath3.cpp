/*
 * https://open.kattis.com/problems/shortestpath3
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
int n, m, q, s, a, b, w;
int dist[1003];
vector<int> check;
bool vis[1003];

void dfs(int u){
    vis[u] = true;
    for (auto v: adj[u])
        if(!vis[v.first])
            dfs(v.first);
}

int main()
{
    while(cin>>n>>m>>q>>s){
        if(!n && !m && !q && !s)
            break;
        fill_n(dist, n, INT_MAX);fill_n(vis, n, false);
        adj.clear();adj.resize(n);check.clear();
        for (int i = 0; i < m; ++i) {
            cin>>a>>b>>w;
            adj[a].push_back({b, w});
        }
        dist[s] = 0;
        for (int i = 0; i < n-1; ++i)
            for (int u=0; u<n; u++)
                for (auto v : adj[u])
                    if(dist[u]!= INT_MAX && dist[u] + v.second < dist[v.first])
                    dist[v.first] = dist[u] + v.second;
        for (int u=0; u<n; u++)
            for (auto v : adj[u])
                if(dist[u]!=INT_MAX && dist[v.first] > dist[u] + v.second)
                    check.push_back(v.first);
        for (auto u : check)
            if(!vis[u])
                dfs(u);
        for (int i = 0; i < q; ++i) {
            cin>>a;
            cout<<((dist[a]==INT_MAX)?"Impossible":((vis[a])?"-Infinity":to_string(dist[a])))<<endl;
        }
        cout<<endl;
    }
    return 0;
}
