/*
 * https://open.kattis.com/problems/nikola
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1003
int dp[MAX_N][MAX_N];
int n;
int fee[MAX_N];

int cdp(int pos, int jump){
    if(dp[pos][jump] != INT_MAX)
        return dp[pos][jump];
    if(pos == n)
        return dp[pos][jump] = fee[n];
    if(pos-jump>=1){
        int x = cdp(pos-jump, jump);
        dp[pos][jump] = min(dp[pos][jump], ((x==INT_MAX)?INT_MAX:x+fee[pos]));
    }
    if(pos+jump+1<=n){
        int x = cdp(pos+jump+1, jump+1);
        dp[pos][jump] = min(dp[pos][jump], ((x==INT_MAX)?INT_MAX:x+fee[pos]));
    }
    return dp[pos][jump];
}

int main()
{
    cin>>n;
    for (int i = 1; i <= n; ++i)
        cin>>fee[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = INT_MAX;
    cout<<cdp(2,1)<<endl;
    return 0;
}

