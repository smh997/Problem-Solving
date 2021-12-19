/*
 * https://open.kattis.com/problems/knapsack
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int dp[2003][2003];
bool ch[2003][2003];
int v[2003], w[2003];
int cdp(int i, int d){
    if(i==0)
        return 0;
//    cout<<i<<" "<<d<<" "<<dp[i][d]<<endl;
    if(dp[i][d] != -1)
        return dp[i][d];
    int ans = -200000;
    if(d>=w[i]){
        ans = v[i] + cdp(i-1, d-w[i]);
    }
    int ans2 = cdp(i-1, d);
//    cout<<i<<" "<<d<<" "<<ans<<" "<<ans2<<endl;
    if(ans > ans2){
        dp[i][d] = ans;
        ch[i][d] = true;
    }
    else{
      dp[i][d] = ans2;
      ch[i][d] = false;
    }
    return dp[i][d];
}

int main()
{
    int c, n;
    while(cin>>c>>n){
        for (int i = 1; i <= n; ++i) {
            cin>>v[i]>>w[i];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= c; ++j) {
                dp[i][j] = -1;
                ch[i][j] = false;
            }
        }
        cdp(n, c);
        vector<int> v;
        for (int i = n; i > 0 && c>=0; --i) {
            if(ch[i][c]){
                v.push_back(i-1);
                c -= w[i];
            }
        }
        cout<<v.size()<<endl;
        for (int i = v.size()-1; i >= 0; --i) {
            cout<<v[i]<<((i!=0)?' ':'\n');
        }
        
    }
    return 0;
}

