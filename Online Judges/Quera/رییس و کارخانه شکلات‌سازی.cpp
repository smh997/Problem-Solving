/*
 * https://quera.org/problemset/20251/
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define adj_list vector<int>
#define ll long long

adj_list g[100003];

pair<ll,ll> dfs(int source){
    ll x = 1, y = 0;
    for(adj_list::iterator v = g[source].begin(); v != g[source].end(); v++){
            pair<ll,ll> tmp = dfs(*v);
            x += tmp.first + tmp.second + 1;
            y += tmp.second + 1;
        }
    return make_pair(x,y);
}
    
int main(){    
    int v;
    cin >> v;
    for(int i = 2; i <= v; i++){
        int a;
        cin >> a;
        g[a].push_back(i);
    }
    cout << dfs(1).first << endl;
}