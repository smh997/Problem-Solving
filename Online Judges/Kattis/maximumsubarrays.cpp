/*
 * https://open.kattis.com/problems/maximumsubarrays
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int

num dp[5003][5003], dp2[5003][5003];
num a[5003];

int main()
{
    int n,k;
    cin>>n>>k;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i <= n; ++i) {
        dp2[i][0] = 0;
        dp[i][0] = 0;
    }dp[0][0]=0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if(i==j){
                dp[i][j] = dp[i-1][j-1]+a[i];
                dp2[i][j] = dp[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j]+a[i], dp2[i-1][j-1]+a[i]);
                dp2[i][j] = max(dp[i][j], dp2[i-1][j]);
            }
//            cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<dp2[i][j]<<endl;
        }
    }
    cout<<dp2[n][k]<<endl;
    return 0;
}

//11 3
//23 -10 12 -2 -33 13 -5 55 23 -8 13
