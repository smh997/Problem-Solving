/*
 * https://open.kattis.com/problems/britishmenu
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100003
int n, m, a, b, nums=0, scc=0;
int dfs_low[MAX_N], dfs_num[MAX_N];
int compo[MAX_N];
int compoSize[MAX_N];
vector<int> adj[MAX_N];
vector<int> s;
int id[MAX_N];
int dist[MAX_N][1<<6];
bool visited[MAX_N];

int cdp(int u, int mask){
    mask |= 1<<id[u];
    if(dist[u][mask])
        return dist[u][mask];
    int res = 0;
    for (auto v: adj[u]) {
        if(compo[u]!=compo[v])
            res = max(res, cdp(v, 0));
        else if(!(mask & 1<<id[v]))
            res = max(res, cdp(v, mask));
    }
    res++;
    return dist[u][mask] = res;
}

void tarj(int u){
    dfs_num[u] = dfs_low[u] = nums++;
    s.push_back(u);visited[u]=true;
    for (auto v: adj[u]) {
        if(dfs_num[v] == -1)
            tarj(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        scc++;
        int w;
        while(true){
            w=s.back();s.pop_back();visited[w]=false;
            compo[w] = scc;id[w] = compoSize[scc]++;
            if(w==u)
                break;
        }
    }
}

int main()
{
    cin>>n>>m;
    fill_n(dfs_num, n+1, -1);
    fill_n(dfs_low, n+1, -1);
    fill_n(visited, n+1, false);
    for (int i = 0; i < m; ++i) {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i)
        if(dfs_num[i] == -1)
            tarj(i);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res = max(res, cdp(i, 0));
    }
    cout<<res<<endl;
    return 0;
}
