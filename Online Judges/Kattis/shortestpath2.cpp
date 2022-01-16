/*
 * https://open.kattis.com/problems/shortestpath2
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<tuple<int, int, int, int>>> adj;
int dist[10003];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;


int main()
{
    int n, m, q, s, u, v, t0, p, d, w;
    pair<int, int> pp;
    while(cin>>n>>m>>q>>s){
        if(!n && !m && !q && !s)
            break;
        adj.clear();
        adj.resize(n);
        fill_n(dist, n, INT_MAX);
        dist[s] = 0;qu.push({0, s});
        for (int i = 0; i < m; ++i) {
            cin>>u>>v>>t0>>p>>d;
            adj[u].push_back(make_tuple(v, t0, p, d));
        }
        while(!qu.empty()){
            pp = qu.top();qu.pop();
            w = pp.first;
            u = pp.second;
            if(w>dist[u])
                continue;
            for (auto vv : adj[u]) {
                v = get<0>(vv); t0 = get<1>(vv); p = get<2>(vv); d = get<3>(vv);
                if(t0>=dist[u] && t0 + d<dist[v]){
                    dist[v] = t0 + d;
                    qu.push({dist[v], v});
                }
                else if(t0<dist[u] && p>0 && (((dist[u]-t0)%p)?p-((dist[u]-t0)%p):0) + dist[u] + d < dist[v]){
                    dist[v] = dist[u] + (((dist[u]-t0)%p)?p-((dist[u]-t0)%p):0) + d;
                    qu.push({dist[v], v});
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
