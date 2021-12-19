/*
 * https://open.kattis.com/problems/greetings
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num inf = LLONG_MAX;

int n, k, w[15 + 3], h[15 + 3];
num q[15 + 3], waste[(1 << 15) + 3], dp[(1 << 15) + 3][15 + 3];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> w[i] >> h[i] >> q[i];
    for(int mask = 1; mask < (1 << n); mask++){
        int maxw = 0, maxh = 0;
        for(int i = 0; i < n; i++)
            if(mask & (1 << i))
                maxw = max(maxw, w[i]), maxh = max(maxh, h[i]);
        for(int i = 0; i < n; i++)
            if(mask & (1 << i))
                waste[mask] += q[i] * (maxw * maxh - w[i] * h[i]);
    }
    for(int mask = 1; mask < (1 << n); mask++){
        dp[mask][0] = inf;
        for(int c = 1; c <= k; c++){
            dp[mask][c] = inf;
            int prevy = mask;
            while(prevy){
                if(dp[mask - prevy][c-1] != inf)
                    dp[mask][c] = min(dp[mask][c], dp[mask - prevy][c-1] + waste[prevy]);
                prevy = (prevy - 1) & mask;
            }
        } 
    }
    cout << dp[(1 << n) - 1][k] << endl;
} 