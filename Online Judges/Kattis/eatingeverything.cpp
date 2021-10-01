/*
 * https://open.kattis.com/problems/eatingeverything
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const int max_size = 500003;
int n, m, s, e;
double c[max_size], dp[max_size];
vector<int> adj[max_size];

double cdp(int i){
    if(dp[i]!= -1)
        return dp[i];
    double ans = c[i];
    for (int j : adj[i]) {
        double val = cdp(j);
        ans = max(ans, max(c[i] + val/2, val));
    }
    return dp[i] = ans;
}


int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> c[i], dp[i] = -1;
    for (int j = 0; j < m; ++j) {
        cin >> s >> e;
        adj[s].push_back(e);
    }
    cout << fixed << setprecision(10) << cdp(0) << endl;
    return 0;
}

