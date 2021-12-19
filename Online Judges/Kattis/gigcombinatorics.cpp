/*
 * https://open.kattis.com/problems/gigcombinatorics
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 3;
const int mod = 1e9 + 7;
int n, a[maxn], dp[maxn][5];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    dp[n][1] = dp[n][2] = dp[n][3] = 0;
    for(int i = n - 1; i >= 0; i--){
        dp[i][1] = dp[i + 1][1];
        if(a[i] == 1)
            dp[i][1] = (dp[i][1] + dp[i + 1][2]) % mod;
        dp[i][2] = dp[i + 1][2];
        if(a[i] == 2)
            dp[i][2] = ((dp[i][2] + dp[i + 1][2]) % mod + dp[i + 1][3]) % mod;
        dp[i][3] = dp[i + 1][3];
        if(a[i] == 3)
            dp[i][3] = (dp[i][3] + 1) % mod;
    }
    cout << dp[0][1] << endl;
}