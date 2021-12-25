/*
 * https://open.kattis.com/problems/researchproductivityindex
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, m;
double dp[103][103];
double pb[103];

void ini(){
    for (int i = 0; i < n+1; ++i)
        for (int j = 0; j < n+1; ++j)
            dp[i][j] = -1;
}

double cdp(int i, int ch){
    if(i==m)
        return ch?pow(ch,(double)ch/m):0;
    if(dp[i][ch]!= -1)
        return dp[i][ch];
    return dp[i][ch] = pb[i]*cdp(i+1, ch+1) + (1-pb[i])*cdp(i+1, ch);
}

int main()
{
    cin>>n;
    for (int i = 0; i < n; ++i)
        cin>>pb[i],pb[i]/=100;
    sort(pb, pb+n, greater<double>());
    double res = 0;
    for (m = 1; m <= n; ++m)
        ini(),res = max(res, cdp(0, 0));
    printf("%.6lf\n", res);
    return 0;
}

