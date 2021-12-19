/*
 * https://open.kattis.com/problems/intercept
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int maxn = 100003;
ll n, m, u, v, w, s, t;
vector<pair<ll, int>> adj[maxn];
vector<int> par_path[maxn];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
ll dist[maxn];
bool vis[maxn];
int dfs_low[maxn], dfs_num[maxn];
int par[maxn];
int cnt = 0;
bool on_the_path[maxn];
set<int> articulation_points;

void dfs(int u){
    vis[u] = true;
    dfs_low[u] = dfs_num[u] = cnt++;
    for(auto vv : adj[u]){
        int v = vv.second;
        if(!on_the_path[v])
            continue;
        if(!vis[v]){
            par[v] = u;
            dfs(v);
            if(dfs_low[v] >= dfs_num[u])
                articulation_points.insert(u);
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != par[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void path_check(int i){
    on_the_path[i] = true;
    if (i == s)
        return;
    for (auto p: par_path[i])
        if (!on_the_path[p])
            path_check(p);
}


int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    cin >> s >> t;
    for (int i = 0; i < n; ++i) {
        dist[i] = LLONG_MAX;
    }
    dist[s] = 0;
    pq.push({0, s});
    pair<ll, int> tp;
    while(!pq.empty()){
        tp = pq.top();pq.pop();
        if(dist[tp.second] < tp.first)
            continue;
        for (auto a: adj[tp.second]) {
            if(dist[tp.second] != LLONG_MAX && dist[a.second] > dist[tp.second] + a.first){
                dist[a.second] = dist[tp.second] + a.first;
                pq.push({dist[a.second], a.second});
                par_path[a.second].clear();
                par_path[a.second].push_back(tp.second);
            }
            else if(dist[tp.second] != LLONG_MAX && dist[a.second] == dist[tp.second] + a.first){
                par_path[a.second].push_back(tp.second);
            }
        }
    }
    path_check(t);
    dfs(s);
    articulation_points.insert(s);
    articulation_points.insert(t);
    for (auto ap: articulation_points) {
        cout << ap << " ";
    }
    return 0;
}

