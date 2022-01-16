/*
 * https://open.kattis.com/problems/shortestpath1
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
int dist[10003];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;


int main()
{
    int n, m, q, s, a, b, w, u;
    pair<int, int> pp;
    while(cin>>n>>m>>q>>s){
        if(!n && !m && !q && !s)
            break;
        adj.clear();
        adj.resize(n);
        
        fill_n(dist, n, INT_MAX);
        dist[s] = 0;qu.push({0, s});
        for (int i = 0; i < m; ++i) {
            cin>>a>>b>>w;
            adj[a].push_back({b, w});
        }
        
        while(!qu.empty()){
            pp = qu.top();qu.pop();
            w = pp.first;
            u = pp.second;
            if(w>dist[u])
                continue;
            for (auto v : adj[u]) {
                if(dist[u]+v.second < dist[v.first]){
                    dist[v.first] = dist[u]+v.second;
                    qu.push({dist[v.first], v.first});
                }
            }
        }
        int v;
        for (int i = 0; i < q; ++i) {
            cin>>v;
            if(dist[v] != INT_MAX)
                cout<<dist[v]<<endl;
            else
                cout<<"Impossible"<<endl;
        }
        cout<<endl;
        
    }
    return 0;
}
