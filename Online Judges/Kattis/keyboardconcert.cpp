/*
 * https://open.kattis.com/problems/keyboardconcert
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, m, dp[1003][1003], k, a, arr[1003];
vector<int> tool[1003];

int cdp(int i, int j){
    if(i == -1){
        return 0;
    }
    
    if(dp[i][j] != INT_MAX){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int kk = 0; kk < tool[arr[i]].size(); ++kk){
        if(tool[arr[i]][kk] == j){
            ans = min(ans, cdp(i-1, tool[arr[i]][kk]));
        }
        else{
            ans = min(ans, 1 + cdp(i-1, tool[arr[i]][kk]));
        }
    }
    return dp[i][j] = ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> a;
            tool[a-1].push_back(i);
        }
    }
    for (int i = 0; i < m; ++i)
        cin >> arr[i], arr[i]--;
    cout << cdp(m-1, n) - 1 << endl;
    return 0;
}

