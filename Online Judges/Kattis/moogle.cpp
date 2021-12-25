/*
 * https://open.kattis.com/problems/moogle
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

double dp[203][203][203];
int a[203], h, c;

double calc(int i, int j){
    double res = 0;
    for (int k = i+1; k < j; ++k)
        res += fabs(a[k] - (a[i] + (a[j]-a[i])*((double)(k-i)/(j-i))));
    return res;
}

double cdp(int i, int j, int k){
    if(j == h-1) return calc(i, j);
    if(dp[i][j][k]!= -1)return dp[i][j][k];
    double res = LDBL_MAX;
    if(k<c-1) res = min(res, calc(i, j)+cdp(j, j+1, k+1));
    if(c-k<h-j)res = min(res, cdp(i, j+1, k));
    return dp[i][j][k] = res;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>h>>c;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < h; ++j)
                for (int k = 0; k < c; ++k)
                    dp[i][j][k] = -1;
        for (int i = 0; i < h; ++i)
            cin>>a[i];
        printf("%.4lf\n", cdp(0, 1, 1)/h);
    }
    return 0;
}

