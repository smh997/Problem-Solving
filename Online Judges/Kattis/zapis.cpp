/*
 * https://open.kattis.com/problems/zapis
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define mod 100000
string op = "{[(";
string cl = "}])";
string str;
#define num long long int
num n;
num dp[203][203];

num cdp(num s, num e){
    
    if(s>=e)
        return 1;
    if(dp[s][e] != -1)
        return dp[s][e];
    num ans=0;
    for (int i = 0; i < 3; ++i)
        if(op[i]==str[s] || str[s] == '?')
            for (int j = s+1; j <= e; j+=2)
                if(cl[i] == str[j] || str[j] == '?'){
                    ans += cdp(s+1, j-1)*cdp(j+1,e);
                    ans = (ans>=mod)? ans%mod +mod:ans;
                }
    return dp[s][e]=ans;
}

int main()
{
    cin>>n>>str;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = -1;
    num ans = cdp(0, n-1);
    if(ans >= mod)
        printf("%05lld\n", ans%mod);
    else
        printf("%lld\n", ans);
    
    
    return 0;
}

