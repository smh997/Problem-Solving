/*
 * https://open.kattis.com/problems/bolk
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, c;
int dp[1003][1003];
pair<int, int> a[1003];

int cdp(int i, int r){
    if(i == n) 
        return 0;
    if(dp[i][r] != -1) 
        return dp[i][r];
    int ans = cdp(i + 1, r);
    if(r >= a[i].first) 
        ans = max(ans, a[i].second + cdp(i + 1, r - a[i].first));
    return dp[i][r] = ans;
}

int main() {
    cin >> n >> c;
    for(int i = 0; i < n; i++) 
        cin >> a[i].first >> a[i].second;
    memset(dp, -1, sizeof(dp));
    cout << cdp(0, c) << endl;
    
    return 0;
}
