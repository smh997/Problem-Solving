/*
 * https://open.kattis.com/problems/shortestpath4
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int dp[1003][33];
int tc, n, m, q, a, b, s, t, k;
vector<vector<pair<int, int>>> adj;


int main()
{
    cin>>tc;
    while(tc--){
        cin>>n;
        adj.clear();
        adj.resize(n);
        for (int i = 0; i < n; ++i) {
            cin>>m;
            for (int j = 0; j < m; ++j) {
                cin>>a>>b;
                adj[a].push_back({i, b});
            }
        }
        cin>>q;
        for (int i = 0; i < q; ++i) {
            cin>>s>>t>>k;
            for (int j = 0; j < n; ++j) {
                for (int f = 0; f < k; ++f) {
                    dp[j][f] = INT_MAX;
                    dp[s][f] = 0;
                }
            }
            for (int j = 1; j < k; ++j) {
                for (int o = 0; o < n; ++o) {
                    for (auto edge : adj[o]) {
                        dp[o][j]=min(dp[o][j], (dp[edge.first][j-1]==INT_MAX)?INT_MAX:dp[edge.first][j-1]+edge.second);
                    }
                }
            }
            cout<<((dp[t][k-1]==INT_MAX)?-1:dp[t][k-1])<<endl;
        }
        cout<<endl;
    }
    return 0;
}

