/*
 * https://open.kattis.com/problems/acquirehardware
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<vector<int>> grid;
char ch;

int main() {
    
    cin >> h >> w;
    grid.resize(h, vector<int>(w, 0));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> ch;
            if (ch == 'I')
                grid[i][j] = 1;
        }
    }
    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i > 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j] + grid[i][j]);
            }
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i][j-1] + grid[i][j]);
            }
        }
    }

    cout << dp[h-1][w-1] << endl;
    
    return 0;
}
