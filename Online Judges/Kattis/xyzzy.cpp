/*
 * https://open.kattis.com/problems/xyzzy
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
int n, m, e, b, w;
int dist[103];
bool vis[103];

bool dfs(int u){
    vis[u] = true;
    bool ans;
    for (auto v: adj[u]){
        if(v.first == n-1)
            return true;
        if(!vis[v.first]){
            ans = dfs(v.first);
            if(ans)
                return true;
        }
    }
    return false;
        
}

int main()
{
    while(cin>>n){
        if(n == -1)
            break;
        fill_n(dist, n, INT_MIN);fill_n(vis, n, false);
        adj.clear();adj.resize(n);
        for (int i = 0; i < n; ++i) {
            cin>>e>>m;
            for (int j = 0; j < m; ++j) {
                cin>>b;b--;
                adj[i].push_back({b, e});
            }
        }
        dist[0] = 100;
        for (int i = 0; i < n-1; ++i)
            for (int u=0; u<n; u++)
                for (auto v : adj[u])
                    if(dist[u]!= INT_MIN && dist[u] + v.second > 0)
                        dist[v.first] = max(dist[v.first], dist[u]+v.second);
        if(dist[n-1]>0){
            cout<<"winnable"<<endl;
            continue;
        }
        bool ans = false;
        for (int u=0; u<n; u++){
            if(ans)
                break;
            for (auto v : adj[u])
                if(dist[u]!= INT_MIN && dist[v.first] < dist[u] + v.second && dist[u]+v.second > 0){
                    fill_n(vis, n, false);
                    if(dfs(u)){
                        ans = true;
                        break;
                    }
                }
        }
        if(ans){
            cout<<"winnable"<<endl;
        }
        else
            cout<<"hopeless"<<endl;
    }
    return 0;
}
