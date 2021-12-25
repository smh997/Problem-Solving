/*
 * https://open.kattis.com/problems/mravi
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, s;bool ss;double k;
vector<vector<pair<int, int>>> adj(1003);
pair<int, bool> edges[1003];
double dist[1003];

void dfs(int u){
    for(auto v: adj[u]){
        k = dist[u];
        c = edges[v.second].first;
        ss = edges[v.second].second;
        if(ss)
            k = sqrt(k);
        k = k *100.0/c;
        dist[v.first] = max(dist[v.first], k);
        dfs(v.first);
    }
}

int main()
{
    cin>>n;
    vector<int> leaves;
    for (int i = 0; i < n-1; ++i) {
        cin>>a>>b>>c>>s;a--;b--;
        adj[b].push_back({a, i});
        edges[i].first = c;
        edges[i].second = s;
    }
    int root;
    fill_n(dist, n, 0);
    for (int i = 0; i < n; ++i) {
        cin>>a;
        if(a!=-1)
            leaves.push_back(i), dist[i]=a;
        if(!adj[i].size())
            root = i;
    }
    for (auto leaf : leaves) {
        dfs(leaf);
    }
    printf("%.4lf\n", dist[root]);
    return 0;
}

