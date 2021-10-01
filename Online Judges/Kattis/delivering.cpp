/*
 * https://open.kattis.com/problems/delivering
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define inf LLONG_MAX

const int maxn = 1e3 + 3;
int n, e, c;
bool pizza[maxn];
vector<pair<num, int>> adjs[maxn];
priority_queue<pair<num, int>, vector<pair<num, int>>, greater<pair<num, int>>> pq;
num dis[maxn];
vector<int> dadjs[maxn];
bool vis[maxn];
int match[maxn];
map<int, int> ids;
int root;

void build(int u){
    vis[u] = 1;
    for(auto x : adjs[u]){
        if(dis[x.second] != dis[u] + x.first)
            continue;
        if(pizza[x.second])
            dadjs[ids[root]].push_back(ids[x.second]);
        if(!vis[x.second])
            build(x.second);
    }
}

bool aug(int u){
    if(vis[u])
        return 0;
    vis[u] = 1;
    for(int v : dadjs[u])
        if(match[v] == -1 || aug(match[v])){
            match[v] = u;
            return 1;
        }
    return 0;
}

int main(){
    cin >> n >> e >> c;
    for(int i = 0; i < c; i++){
        int x;
        cin >> x;
        pizza[x] = 1;
    }
    pizza[0] = 1;
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adjs[u].push_back({w, v});
    }
    fill_n(dis, n, inf);
    pq.push({0, 0});
    dis[0] = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int u = p.second;
        num d = p.first;
        if(dis[u] < d)
            continue;
        for(auto x : adjs[u])
            if(dis[x.second] > d + x.first)
                dis[x.second] = d + x.first, pq.push({dis[x.second], x.second});
    }
    for(int i = 0; i < n; i++)
        if(pizza[i])
            ids[i] = ids.size();
    for(int i = 0; i < n; i++)
        if(pizza[i])
            fill_n(vis, n, 0), root = i, build(i);
    fill_n(match, c + 1, -1);
    int ans = 0;
    for(int i = 0; i < c + 1; i++){
        fill_n(vis, c + 1, 0);
        ans += aug(i);
    }
    cout << c + 1 - ans << endl;
}