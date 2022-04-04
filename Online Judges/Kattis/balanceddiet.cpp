/*
 * https://open.kattis.com/problems/balanceddiet
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int n;
int s[23];
int dp[23][12003];

int main()
{
    while(cin >> n && n ){
        int ss = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            ss += s[i];
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= ss / 2; ++j) {
                if (i * j == 0)
                    dp[i][j] = 0;
                else if (s[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], s[i - 1] + dp[i - 1][j - s[i - 1]]);
            }
        }
        int ans2 = dp[n][ss / 2];
        int ans1 = ss - ans2;

        cout << ans1 << " " << ans2 << endl;
    }
    
    return 0;
}
