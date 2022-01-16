/*
 * https://codeforces.com/contest/489/problem/E
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
double dp[1003][1003], f;
int ans[1003][1003];
int l, n, b[1003], x[1003];

double cdp(int i, int pre){
    if(dp[i][pre] != -1){
        return dp[i][pre];
    }
    if(i == n){
        ans[n][pre] = n;
        return (sqrt(1.0*abs(l-(x[i]-x[pre]))) - f * b[i]);
    }
    double tmp = cdp(i+1, pre);
    double tmp2 = cdp(i+1, i) + (sqrt(1.0*abs(l-(x[i]-x[pre]))) - f * b[i]);
    if(tmp < tmp2){
        ans[i][pre] = ans[i+1][pre];
        return dp[i][pre] = tmp;
    }
    ans[i][pre] = i;
    return dp[i][pre] = tmp2;
}

int main()
{
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> x[i+1] >> b[i+1];
    }
    double lo = 0, hi = INT_MAX;
    while(fabs(lo-hi)>EPS){
        for (int i = 0; i < n+1; ++i) {
            for (int j = 0; j < n+1; ++j) {
                dp[i][j] = -1;
            }
        }
        f = (lo + hi) / 2;
        if(cdp(1, 0) < 0){
            hi = f;
        }
        else{
            lo = f;
        }
    }
//    cout << lo << endl;
    int res = ans[1][0];
    int cur = 1, prev = 0;
    while(res != n){
        if(cur == res){
            cout << res << " ";
            res = ans[cur+1][cur];
            prev = cur;
            cur++;
            continue;
        }
        res = ans[res][prev];
        cur++;
    }
    cout << n << endl;
    return 0;
}