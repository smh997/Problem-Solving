/*
 * https://open.kattis.com/problems/cardmagic
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000009
long long int dp[103][5003];
long long int n, k, t;

int main()
{
    cin>>n>>k>>t;
    for (int i = t-1; i >= max(0LL, t-k); --i) {
        dp[0][i]=1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = t-(i+1); j >= max(0LL, t-(i+1)*k); --j) {
            dp[i][j]=0;
            for (int f = min(j+k, t-i); f >= max((long long)j+1, t-(i+1)*k); --f) {
                dp[i][j] = (dp[i][j] + dp[i-1][f])%mod;
            }
        }
    }
    cout<<dp[n-1][0]<<endl;
    return 0;
}

