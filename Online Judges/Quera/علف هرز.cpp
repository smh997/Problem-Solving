/*
 * https://quera.org/problemset/80650/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int n, m, q, dp[1000][1000];

int main(){
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> dp[i][j];
    for(int k = 0; k < 100000000 / (n * m); k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                dp[i][j] = min(dp[i][j], dp[(i + 1) % n][j] + dp[i][(j + 1) % m]);
    int x, y, ans = 0;
    while(q--)
        cin >> x >> y, ans += dp[x][y];
    cout << ans << endl; 
}
