/*
 * https://open.kattis.com/problems/centsavings
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int dp[2003][24], arr[2003];

int rnd(int s){
    return ((s%10>=5)?s+(10-(s%10)):s-(s%10));
}
int main()
{
    int n, g, res;
    cin>>n>>g;
    cin>>arr[1],g++;
    for (int i = 2; i <= n; ++i) {
        cin>>arr[i], arr[i] += arr[i-1];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = rnd(arr[i]);
    }
    res = dp[n][1];
    for (int k = 2; k <= min(g, n); ++k) {
        for (int i = 1; i <= n; ++i) {
            dp[i][k] = INT_MAX;
            for (int j = 1; j <= i; ++j) {
                if(dp[j][k-1] == INT_MAX){
                    continue;
                }
                dp[i][k] = min(dp[i][k], dp[j][k-1] + rnd(arr[i]-arr[j]));
            }
        }
        res = min(dp[n][k], res);
    }
    cout<<res<<endl;
    return 0;
}
