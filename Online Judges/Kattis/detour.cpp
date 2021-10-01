/*
 * https://open.kattis.com/problems/detour
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100003
vector<pair<int, int>> adj[MAX_N];
long long int dist[MAX_N];
int par[MAX_N];
bool vis[MAX_N];
map<pair<int, int>, bool> mp;
priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
int n, m, a, b, d;
bool flag = false;

void dfs(int u){
    vis[u]=true;
    if(u == 1){
        flag = true;
        return;
    }
    for (auto edge : adj[u]) {
        if(/*!mp[{u, edge.first}]*/dist[u]!=dist[edge.first]+edge.second && !vis[edge.first]){
            par[edge.first]=u;
            dfs(edge.first);
            if(flag)
                return;
        }
    }
}

int main()
{
    cin>>n>>m;
    fill_n(dist, n, LLONG_MAX);
    fill_n(vis, n, false);
    for (int i = 0; i < m; ++i) {
        cin>>a>>b>>d;
//        mp[{a, b}] = false;mp[{b, a}] = false;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    pq.push({0LL, 1});
    dist[1]=0LL;
    pair<long long int, int> p;
    while(!pq.empty()){
        p = pq.top(); pq.pop();
        if(p.first>dist[p.second])
            continue;
//        mp[{p.first, p.second}] = true;
//        mp[{p.second, p.first}] = true;
        for (auto edge : adj[p.second]) {
            if(dist[edge.first]==LLONG_MAX || dist[edge.first] > dist[p.second]+edge.second){
                dist[edge.first] = dist[p.second]+edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }
    par[0]=-1;
    dfs(0);
    if(vis[1]){
        vector<int> path;
        int curr = 1;
        while(curr!=-1){
            path.push_back(curr);
            curr = par[curr];
        }
        cout<<path.size()<<" ";
        for (int i = path.size()-1; i >= 0; --i) {
            cout<<path[i]<<((i==0)?"\n":" ");
        }
    }
    else{
        cout<<"impossible"<<endl;
    }
    return 0;
}
