/*
 * https://open.kattis.com/problems/sailingfriends
 * Author: https://github.com/smh997/
 */

#include<bits/stdc++.h>
using namespace std;

int n, b, m, tmp, fa, fb;
int ans = 0;
bool has_boat[100003];
bool vis[100003];
bool flag;
vector<int> adj[100005];

void dfs(int u){
    vis[u] = true;
    if(has_boat[u])
        flag = false;
    for(auto v: adj[u]){
        if(!vis[v])
            dfs(v);
    }
}

int main(){
    cin >> n >> b >> m;
    for (int i = 0; i < b; i++){
        cin >> tmp;
        has_boat[tmp] = true;
    }
    for (int i = 0; i < m; i++){
        cin >> fa >> fb;
        adj[fb].push_back(fa);
        adj[fa].push_back(fb);
    }
    fill_n(vis, n+1, false);
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            flag = true;
            dfs(i);
            if(flag)
                ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}