/*
 * https://open.kattis.com/problems/ivana
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
int dp[103][103][206][2];
int a[103];

int cdp(int l, int r, int o, int flag){
    if(dp[l][r][o][flag]!= -1){
//        cout<<l<<" "<<r<<" "<<o<<" "<<flag<<" "<<dp[l][r][o][flag]<<endl;
        return dp[l][r][o][flag];
    }
    if(l==r){
        if(flag){
            if(a[l]%2){
                o++;
            }
        }
        else if(a[l]%2){
            o--;
        }
//        cout<<l<<" "<<r<<" "<<o<<" "<<flag<<endl;
        if(o>100)
            return true;
        else
            return false;   
    }
    int lans, rans;
    if(flag){
        if(a[l]%2)
            lans = cdp((l-1+n)%n, r, o+1, !flag);
        else
            lans = cdp((l-1+n)%n, r, o, !flag);
        if(a[r]%2)
            rans = cdp(l, (r+1)%n, o+1, !flag);
        else
            rans = cdp(l, (r+1)%n, o, !flag);
        dp[l][r][o][flag] =  lans || rans;
    }
    else{
        if(a[l]%2)
            lans = cdp((l-1+n)%n, r, o-1, !flag);
        else
            lans = cdp((l-1+n)%n, r, o, !flag);
        if(a[r]%2)
            rans = cdp(l, (r+1)%n, o-1, !flag);
        else
            rans = cdp(l, (r+1)%n, o, !flag);
        dp[l][r][o][flag] =  lans && rans;
    }
    
    return dp[l][r][o][flag];
}

int main()
{
    int ans;
    
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 206; ++k) {
                dp[i][j][k][0]=-1;
                dp[i][j][k][1]=-1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
//        cout<<i<<endl;
        if(a[i]%2)
            ans = cdp((i-1+n)%n, (i+1)%n, 101, 0);
        else
            ans = cdp((i-1+n)%n, (i+1)%n, 100, 0);
//        cout<<ans<<endl;
        if(ans)
            res++;
    }
    cout<<res<<endl;
    return 0;
}

