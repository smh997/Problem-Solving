/*
 * https://open.kattis.com/problems/narrowartgallery
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int dp[203][3][203];
int a[203][2];

int main()
{
    int n, K;
    cin>>n>>K;
    for (int i = 0; i <= n; ++i) {
        cin>>a[i][0]>>a[i][1];
    }
    for (int i = 0; i < n+1; ++i) {
        dp[0][0][i] = dp[0][1][i] = dp[0][2][i] = -1;
    }
    dp[0][0][0] = a[0][0] + a[0][1];
    dp[0][1][1] = a[0][1];
    dp[0][2][1] = a[0][0];
    for (int i = 1; i < n; ++i) {
        for (int k = 0; k <= K; ++k) {
            dp[i][0][k] = ((max(dp[i-1][0][k], max(dp[i-1][1][k], dp[i-1][2][k]))!= -1)?a[i][0] + a[i][1] + max(dp[i-1][0][k], max(dp[i-1][1][k], dp[i-1][2][k])):-1);
            dp[i][1][k] = ((k==0)?-1:((max(dp[i-1][1][k-1], dp[i-1][0][k-1])!=-1)?a[i][1] + max(dp[i-1][1][k-1], dp[i-1][0][k-1]):-1));
            dp[i][2][k] = ((k==0)?-1:((max(dp[i-1][2][k-1], dp[i-1][0][k-1])!=-1)?a[i][0] + max(dp[i-1][2][k-1], dp[i-1][0][k-1]):-1));
        }
    }
    dp[n][0][K] = max(dp[n-1][0][K], max(dp[n-1][1][K], dp[n-1][2][K]));
    cout<<dp[n][0][K]<<endl;
    return 0;
}