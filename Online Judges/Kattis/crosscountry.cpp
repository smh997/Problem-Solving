/*
 * https://open.kattis.com/problems/crosscountry
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<pair<int, int>>> adj(1003);
int dist[1003];
int n, s, t;
int w, u;

int main()
{
    cin>>n>>s>>t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>w;
            if(i==j)
                continue;
            adj[i].push_back({j, w});
        }
    }
    fill_n(dist, n, INT_MAX);
    dist[s]=0;
    pq.push({0, s});
    pair<int, int> pp;
    while(!pq.empty()){
        pp = pq.top(); pq.pop();
        w = pp.first;
        u = pp.second;
        if(w>dist[u])
            continue;
        for(auto v: adj[u]){
            if(dist[u]+v.second<dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
    cout<<dist[t]<<endl;
    return 0;
}

