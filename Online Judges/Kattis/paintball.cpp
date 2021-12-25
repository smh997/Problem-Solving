/*
 * https://open.kattis.com/problems/paintball
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

// Maximum Cardinality Bipartite Matching
// O(V * E)

const int maxn = 1003;
const int maxm = 1003;

// n is |left set|, m is |right set|, edges are from left set to right set
int n, m, mm, s, v;
vector<int> adjs[maxn];
bool vis[maxn];
int match[maxm]; // if match[v] = u then u from left set is matched with v from right set

int aug(int u){
    if(vis[u])  
        return 0;
    vis[u] = 1;
    for(int v : adjs[u])
        if(match[v] == -1 || aug(match[v])){
            match[v] = u;
            return 1;
        }
    return 0;
}

int a, b;

int main()
{
    cin >> n >> mm; m = n;
    for (int i = 0; i < mm; ++i) {
        cin >> a >> b; a--, b--;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    int ans = 0;
    fill_n(match, m, -1);
    for(int i = 0; i < n; i++){
        fill_n(vis, n, 0);
        ans += aug(i);
    }
    if(ans != m){
        cout << "Impossible" << endl;
        return 0;
    }
    int res[n];
    for (int i = 0; i < m; ++i) {
        res[match[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i]+1 << endl;
    }
    return 0;
}

