/*
 * https://open.kattis.com/problems/programmingteam
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9

double dp[2503][2503], tot;
int p[2503], s[2503];
int order[2503], cnt = 0;
int parent[2503], nexty[2503];
int n, K, a;
vector<int> adj[2503];

void dfs(int u){
    int nobat = cnt;
    order[cnt++] = u;
    for(auto v: adj[u]){
        if(parent[u] != v){
            parent[v] = u;
            dfs(v);
        }
    }
    nexty[nobat] = cnt;
}

double cdp(int i, int k){
    if(dp[i][k] != -1){
        return dp[i][k];
    }
    if(k==0){
        return 0;
    }
    if(i == 0){
        return dp[i][k] = cdp(i+1, k);
    }
    if(n-i+1 == k){
        return dp[i][k] = cdp(i+1, k-1) + (p[order[i]] - tot * s[order[i]]);
    }
    double res = cdp(i+1, k-1) + (1.0*p[order[i]] - tot * s[order[i]]);
    if(n - nexty[i] + 1 >= k){
        res = max(res, cdp(nexty[i], k));
    }
    return dp[i][k] = res;
}

int main()
{
    cin >> K >> n;
    fill_n(parent, n+1, -1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] >> p[i] >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    dfs(0);
    double lo = 0, hi = INT_MAX;
    while(fabs(lo-hi) > EPS){
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= K; ++j) {
                dp[i][j] = -1;
            }
        }
        tot = (lo + hi) / 2;
        if(cdp(0, K) < 0){
            hi = tot;
        }
        else{
            lo = tot;
        }
    }
    cout << fixed << setprecision(3) << lo << endl;
    return 0;
}

