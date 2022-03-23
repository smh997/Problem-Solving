/*
 * https://quera.org/problemset/6403/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int n, k;
long long int dp[103], dp2[103][103];
int a[103];

long long int cdp(int i, int j){
    if(dp2[i][j] != -1)
        return dp2[i][j];
    dp2[i][j] = LLONG_MAX;
    for (int m = i+1; m < j; ++m) {
        if(dp2[i][m] == -1)
            dp2[i][m] = cdp(i, m);
        if(dp2[m][j] == -1)
            dp2[m][j] = cdp(m, j);
        if(dp[m - 1] - dp[i] + a[i] + dp[j - 1] - dp[m] + a[m] + dp2[i][m] + dp2[m][j] <= dp2[i][j]){
            dp2[i][j] = dp2[i][m] + dp2[m][j] + dp[m - 1] - dp[i] + a[i] + dp[j - 1] - dp[m] + a[m];
        }
    }
    return dp2[i][j];
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < 103; ++i) {
        dp[i] = 0;
    }
    cin >> a[0];
    dp[0] = a[0];
    for (int i = 1; i < k; ++i) {
        cin >> a[i];
        dp[i] = a[i] + dp[i - 1];
    }
    for (int i = 0; i < k + 1; ++i) {
        for (int j = 0; j < k + 1; ++j) {
            if(j - i <= 1){
                dp2[i][j] = 0;
            }
            else {
                dp2[i][j] = -1;
            }
        }
    }
    cout << cdp(0, k) << endl;
    return 0;
}