/*
 * https://open.kattis.com/problems/canonical
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 103

int n;
int denoms[MAX_N];
int dp[2000003];
int main()
{
    cin>>n;
    for (int i = 0; i < n; ++i)
        cin>>denoms[i];
    dp[0]=0;
    int total = denoms[n-1] + denoms[n-2];
    for (int i = 1; i < total; ++i) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if(i>=denoms[j])
                dp[i] = min(dp[i], dp[i-denoms[j]]+1);
        }
        int ans = 0, c=i;
        while(c){
            int j = upper_bound(denoms, denoms+n, c)-1-denoms;
            ans += c/denoms[j];
            c %= denoms[j];
        }
        if(ans!=dp[i]){
            cout<<"non-canonical"<<endl;
            return 0;
        }
    }
    cout<<"canonical"<<endl;
    return 0;
}

