/*
 * https://quera.org/problemset/138020/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int n, C;
int f[21];
int dp[(1<<18)+3];
int cap[(1<<18)+3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int csum = 0;
    cin >> n >> C;
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        if(f[i] == C)
            csum++;
    }
    dp[0] = 0;
    if(csum == n || csum == n-1){
        cout << n << endl;
        return 0;
    }
    for (int i = 1; i < (1<<n); ++i) {
        dp[i] = 1e9;
        int sum = 0;
        for (int b = 0; b < n; ++b) {
            if(i & (1<<b)){
                sum += f[b];
            }
        }
        cap[i] = sum;
        if(cap[i] <= C)
            dp[i] = 1;
    }
    for (int mask = 1; mask < (1<<n); ++mask) {
        if(dp[mask] != 1e9)
            continue;
        int prevy = mask & (mask-1);
        while(prevy != 0){
            dp[mask] = min(dp[mask], dp[mask-prevy] + dp[prevy]);
            prevy = mask & (prevy-1);
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}

