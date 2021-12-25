/*
 * https://open.kattis.com/problems/scenes
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int dp[103][10003];
long long int n, w, h;

int main()
{
    cin>>n>>w>>h;
    
    for (int i = n; i >= max(0LL, n-h); --i)
        dp[0][i] = 1;
    for (int i = 1; i < w; ++i) {
        for (int j = n; j >= max(0LL, n-(i+1)*h); --j) {
            dp[i][j]=0;
            for (int k = min(n, j+h); k >= j; --k) {
                dp[i][j]= (dp[i][j] + dp[i-1][k])%mod;
            }
        }
    }
    long long int res=0;
    for (int i = 0; i <= n; ++i) {
        res = (res + dp[w-1][i])%mod; 
    }
    res -= min(h+1, n/w+1);
    cout<<res<<endl;
    
    
    return 0;
}

