/*
 * https://open.kattis.com/problems/joggingtrails
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int deg[20];
int n, m, a, b, d;
vector<pair<int, int>> adj[20];
bool matadj[20][20];
vector<int> candids;
long long int dp[(1<<15)+3];
long long int sp[20][20];

long long int cdp(int mask){
    if(dp[mask] != -1){
        return dp[mask];
    }
    if(mask == 0){
        return 0;
    }
    long long int ans = INT_MAX;
    for (int i = 0; i < n; ++i)
        if(mask & (1<<i))
            for (int j = i+1; j < n; ++j)
                if(mask & (1<<j))
                    ans = min(ans, ((matadj[i][j])?0:sp[i][j])+cdp(mask ^ (1<<i | 1<<j)));
    return dp[mask] = ans;
}

int main()
{
    while(cin >> n && n){
        cin >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matadj[i][j] = false;
            }
            adj[i].clear();
            deg[i] = 0;
        }
        fill_n(dp, (1<<n), -1);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(i == j)
                    sp[i][j] = 0;
                else
                    sp[i][j] = INT_MAX;
            }
        candids.clear();
        long long int ans = 0;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> d;
            a--, b--;
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});            
            deg[a]++;
            deg[b]++;
            ans += d;
            sp[a][b] = sp[b][a] = min(sp[a][b], (long long int)d);
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(sp[i][k] != INT_MAX && sp[k][j] != INT_MAX && sp[i][k] + sp[k][j] < sp[i][j])
                        sp[i][j] = sp[i][k] + sp[k][j];
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            if(deg[i]%2){
                candids.push_back(i);
                mask |= 1 << i;
            }
        }
        cout << ans + cdp(mask) << endl;
    }    
    return 0;
}

