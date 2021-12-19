/*
 * https://open.kattis.com/problems/goodcoalition
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8

double dp[153][153];
int s[153], p[153], n, t;


double cdp(int i, int j){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(i == n){
        if(j >= 76){
            return 1;
        }
        return 0;
    }
    double res = cdp(i+1, j);
    if(res < EPS){
        res = 0;
    }
    res = max(res, cdp(i+1, j+s[i]) * p[i] / 100);
    if(res < EPS){
        res = 0;
    }
    return dp[i][j] = res;
}


int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n+1; ++i) {
            for (int j = 0; j < 153; ++j) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> s[i] >> p[i];
        }
        cout << fixed << setprecision(7) << cdp(0, 0) * 100.0 << endl;
    }
    return 0;
}

