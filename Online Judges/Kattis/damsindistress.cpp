/*
 * https://open.kattis.com/problems/damsindistress
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 2e5 + 3;
num n, w;
int par[maxn];
vector<int> adjs[maxn];
num water[maxn], capacity[maxn];
num ans = LLONG_MAX;

void dfs(int u, num r){
    num c = capacity[u] - water[u], w = water[u];
    ans = min(ans, c + max(r - w - c, 0LL));
    for(int v : adjs[u])
        dfs(v, max(c, r - w));
}

int main(){
    cin >> n >> w;
    for(int i = 1; i <= n; i++){
        cin >> par[i];
        adjs[par[i]].push_back(i);
        cin >> capacity[i] >> water[i];
    }
    capacity[0] = w;
    dfs(0, 0);
    cout << ans << endl;
}