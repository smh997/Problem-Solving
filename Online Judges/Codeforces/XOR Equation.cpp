/*
 * https://codeforces.com/contest/627/problem/A
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

long long int s, x, n, a;
long long int dp[100][2][2];

long long int cdp(int i, int j, int k){
    if(i == n){
        return j&&k;
    }
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    if(x & (1LL<<i)){
        return dp[i][j][k] = cdp(i+1, j|0, k|1) + cdp(i+1, j|1, k|0);
    }
    if(a & (1LL<<i)){
        return dp[i][j][k] = cdp(i+1, j|1, k|1);
    }
    return dp[i][j][k] = cdp(i+1, j|0, k|0);
}


int main()
{
    cin >> s >> x;
    n = ceil(log2(s));
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    if((s-x)%2){
        cout << 0 << endl;
        return 0;
    }
    a = (s-x)/2;
    if(a & x){
        cout << 0 << endl;
        return 0;
    }
    cout << cdp(0, 0, 0) << endl;
    return 0;
}
 