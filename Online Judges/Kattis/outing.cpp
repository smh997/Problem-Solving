/*
 * https://open.kattis.com/problems/outing
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, k, p[1003], lp[1003], cnt = 0, lo[1003], hi[1003];

int dp[1003][1003];

int cdp(int i, int k){
    if(dp[i][k] != -1)
        return dp[i][k];
    if(i == cnt)
        return dp[i][k] = 0;
    int ans = cdp(i + 1, k);
    for(int g = lo[i]; g <= hi[i]; g++){
        if(g > k)
            break;
        ans = max(ans, g + cdp(i+1, k-g));
    }
    return dp[i][k] = ans;
}


int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> p[i], p[i]--;
    fill_n(lp, n, -1);
    for(int i = 0; i < n; i++){
        if(lp[i] != -1)
            continue;
        bool self = false;
        int it = p[i], maxit = n;
        while(maxit){
            if(it == i){
                self = true;
                break;
            }
            it = p[it];
            maxit--;
        }
        if(self){
            lp[i] = cnt;
            lo[cnt] = hi[cnt] = 1; 
            int it = p[i];
            while(it != i){
                lp[it] = cnt;
                lo[cnt]++;
                hi[cnt]++;
                it = p[it];
            }
            cnt++;
        }
    }
    for(int i = 0; i < n; i++)
        if(lp[i] == -1){
            int it = p[i];
            while(lp[it] == -1)
                it = p[it];
            int id = lp[it];
            lp[i] = id;
            hi[id]++;
            it = p[i];
            while(lp[it] == -1)
                lp[it] = id, hi[id]++, it = p[it];
        }
    for(int i = 0; i < 1003; i++)
        for(int j = 0; j < 1003; j++)
            dp[i][j] = -1;
    cout << cdp(0, k) << endl;
}