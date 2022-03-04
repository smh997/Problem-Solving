/*
 * https://quera.org/problemset/82388/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, m;
vector<int> adj[maxn];
int vis[maxn], par[maxn];
int cnt = 0, dfsn[maxn], dfsl[maxn];

set<int> ap;

void dfs(int u){
    vis[u] = 1, dfsn[u] = dfsl[u] = cnt++;
    for(int v : adj[u]){
        if(!vis[v]){
            par[v] = u, dfs(v);
            if(dfsl[v] >= dfsn[u])
                ap.insert(u);
            dfsl[u] = min(dfsl[u], dfsl[v]);
        }
        else if(v != par[u])
            dfsl[u] = min(dfsl[u], dfsn[v]);
    }
    vis[u] = 2;
}

set<int> forces;

int main(){
    int b, x, y;
    cin >> n >> m >> b;
    while(m--)
        cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    while(b--)
        cin >> x, forces.insert(x), adj[0].push_back(x), adj[x].push_back(0);
    dfs(0);
    ap.erase(0);
    for(int f : forces)
        ap.erase(f);
    cout << ap.size() << endl;
    for(int a : ap)
        cout << a << " ";
}