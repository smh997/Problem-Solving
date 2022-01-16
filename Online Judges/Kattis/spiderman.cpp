/*
 * https://open.kattis.com/problems/spiderman
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int dp[43][1003], a[43], s[43];
string res[43][1003];

int cdp(int i, int j){
    if(dp[i][j]!=INT_MAX || i==0)
        return dp[i][j];
    
    int aa = ((j+a[i]<=s[i-1])?cdp(i-1,j+a[i]):INT_MAX);
    int bb = ((j>=a[i])?max(cdp(i-1, j-a[i]), j):INT_MAX);
    dp[i][j] = min(aa, bb);
    if(aa!=INT_MAX && dp[i][j]==aa){
        res[i][j] = res[i-1][j+a[i]]+"D";
    }
    else if(bb != INT_MAX && dp[i][j] == bb){
        res[i][j] = res[i-1][j-a[i]]+"U";
    }
    return dp[i][j];
}


int main()
{
    int n, m;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>m;
        cin>>a[0];
        s[0] = a[0];
        for (int j = 1; j < m; ++j) {
            cin>>a[j];
            s[j] = s[j-1]+a[j];
        }
        if(m==1 || s[m-1]%2){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k <= s[m-1]; ++k) {
                dp[j][k] = INT_MAX;
                res[j][k] = "";
            }
        }
        dp[0][a[0]]= a[0];res[0][a[0]] = "U";
        dp[m-1][0] = cdp(m-2, a[m-1]);
        res[m-1][0] = res[m-2][a[m-1]]+"D"; 
        
        if(dp[m-1][0]!=INT_MAX){
            cout<<res[m-1][0]<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}

