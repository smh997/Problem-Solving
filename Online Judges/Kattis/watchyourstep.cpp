/*
 * https://open.kattis.com/problems/watchyourstep
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, m = 0;
vector<int> adj[2503];
int cnt = 1;
int dfsn[2503], dfsl[2503], vis[2503];
stack<int> st;
vector<int> scc;

void dfs(int u){
    dfsn[u] = dfsl[u] = cnt++;
    vis[u] = 1;
    st.push(u);
    for(int v : adj[u]){
        if(!dfsn[v])
            dfs(v);
        if(vis[v])
            dfsl[u] = min(dfsl[u], dfsl[v]);
    }
    if(dfsl[u] == dfsn[u]){
        int cc = 0;
        while(1){
            int x = st.top();
            st.pop();
            vis[x] = 0;
            cc++;
            if(x == u)
                break;
        }
        scc.push_back(cc);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            int w;
            cin >> w;
            if(w)
                adj[i].push_back(j), m++;
        }
    for(int i = 0; i < n; i++)
        if(!dfsn[i])
            dfs(i);
    long long int ans = 0;
    for(int i = 0; i < scc.size(); i++){
        ans += scc[i] * (scc[i] - 1);
        for(int j = i + 1; j < scc.size(); j++)
            ans += scc[i] * scc[j];
    }
    cout << ans - m << endl;
}