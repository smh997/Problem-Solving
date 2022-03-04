/*
 * https://quera.org/problemset/10234/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[13][10003];
int a[103];

int cdp(int i, int j){
    if (i == -1)
        return (j == 0) ? 0 : -1;
    if (dp[i][j] != -2)
        return dp[i][j];
    
    int cost, tmp;
    dp[i][j] = INT_MAX;
    for (int k = 0; k <= max(a[i], int(sqrt(j))); ++k) {
        if(j - (k * k) >= 0){
            cost = (k - a[i]) * (k - a[i]);
            tmp = cdp(i - 1, j - (k * k));
            if(tmp != -1)
                dp[i][j] = min(dp[i][j], cost + tmp);
            
        }
    }

    if(dp[i][j] == INT_MAX)
        dp[i][j] = -1;
    return dp[i][j];
}

int main()
{
    cin>> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 10003; ++j) {
            dp[i][j] = -2;
        }
    }
    cout << cdp(n-1, m) << endl;
    return 0;
}

