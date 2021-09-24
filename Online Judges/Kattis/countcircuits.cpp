/*
 * https://open.kattis.com/problems/countcircuits
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[43];

long long int dp[43][803][803];

long long int cdp(int i, int d1, int d2){
    if(i == -1)
        return d1 == 0 && d2 == 0;
    if(dp[i][d1+400][d2+400] != -1)
        return dp[i][d1+400][d2+400];
    return dp[i][d1+400][d2+400] = cdp(i-1, d1, d2) + cdp(i-1, d1 + a[i].first, d2 + a[i].second);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 803; j++)
            for(int k = 0; k < 803; k++)
                dp[i][j][k] = -1;
    cout << cdp(n-1, 0, 0) - 1 << endl;
}