#include <bits/stdc++.h>
using namespace std;

// Lowest Common Ancestor

// O(log(n)) per query

const int maxn = 1e5 + 3;
int n, height[maxn], first[maxn], t[8 * maxn];
vector<int> euler;
vector<int> adjs[maxn];
bool vis[maxn];

void build(int v, int tl, int tr){
    if(tl == tr)
        t[v] = euler[tl];
    else{
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        int l = t[2 * v], r = t[2 * v + 1];
        t[v] = (height[l] <= height[r]) ? l : r;
    }
}

void dfs(int u, int h){
    vis[u] = 1;
    first[u] = euler.size();
    height[u] = h;
    euler.push_back(u);
    for(int v : adjs[u])
        if(!vis[v]){
            dfs(v, h + 1);
            euler.push_back(u);
        }
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return -1;
    if(tl == l && tr == r)
        return t[v];
    int tm = (tl + tr) / 2;
    int p1 = query(2 * v, tl, tm, l, min(tm, r));
    int p2 = query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    if(p1 == -1)
        return p2;
    if(p2 == -1)
        return p1;
    return (height[p1] <= height[p2]) ? p1 : p2;
}

int lca(int u, int v){
    if(first[u] > first[v])
        swap(u, v);
    return query(1, 0, euler.size() - 1, first[u], first[v]);
}

int main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adjs[u].push_back(v), adjs[v].push_back(u);
    }
    dfs(0, 0);
    build(1, 0, euler.size() - 1);
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
}