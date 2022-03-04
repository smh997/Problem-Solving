/*
 * https://quera.org/problemset/6396/
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100003

vector<int> adj[MAX_N];
long long int n, a, b, ind, d, md;
bool vis[MAX_N];
void dfs(int u){
    vis[u] = true;
    if(md < d){
        md = d;
        ind = u;
    }
    for(auto v: adj[u]){
        if(!vis[v]){
            d++;
            dfs(v);
            d--;
        }
    }
}

int main()
{
    cin>>n;
    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    d = md = 0;
    dfs(a);
    fill_n(vis, n, false);
    d = md = 0;
    dfs(ind);
    cout << md << " " << (n * (n - 1)) / 2 << endl;
    return 0;
}

