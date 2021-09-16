/*
 * https://open.kattis.com/problems/brexitnegotiations
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 3;

int n, e[maxn], f[maxn], indeg[maxn];
vector<int> adj[maxn];

int dp(int u){
    if(f[u] != -1)
        return f[u];
    int ans = e[u];
    for(int v : adj[u])
        ans = max(ans, dp(v));
    return f[u] = ans;
}

priority_queue<pair<int, int>> kahn;

int main(){
    cin >> n;
    int d, x;
    for(int i = 0; i < n; i++){
        cin >> e[i] >> d;
        while(d--)
            cin >> x, adj[x-1].push_back(i), indeg[i]++;
    }
    fill_n(f, n, -1);
    for(int i = 0; i < n; i++)
        dp(i);
    for(int i = 0; i < n; i++)
        if(!indeg[i])
            kahn.push({f[i], i});
    int ans = 0, cnt = 0;
    while(!kahn.empty()){
        int u = kahn.top().second;
        kahn.pop();
        ans = max(ans, e[u] + cnt);
        cnt++;
        for(int v : adj[u]){
            indeg[v]--;
            if(!indeg[v])
                kahn.push({f[v], v});
        }
    }
    cout << ans << endl;
    return 0;
}

