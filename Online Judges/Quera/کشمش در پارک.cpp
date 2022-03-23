/*
 * https://quera.org/problemset/51867/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

long long int dp[1003][1003];
int arr[1003][1003];


int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    dp[0][0] = arr[0][0];
    for (int i = 0; i < m; ++i) {
        dp[0][i] = arr[0][i];
        if(i > 0 && arr[0][i - 1] != 0)
            dp[0][i] = dp[0][i - 1] + arr[0][i];
    }
    for (int i = 2; i < n; i += 2) {
        for (int j = 0; j < m; ++j) {
            if(arr[i][j] == 0){
                dp[i][j] = -1;
                continue;
            }
            long long int res = -1;
            if(j > 0 && arr[i][j - 1] != 0)
                res = max(dp[i][j - 1], res);
            if((n - i - 1) % 4 == 0 && j > 0 && arr[i - 2][j - 1] != 0){
                res = max(dp[i - 2][j - 1], res);
            }
            else if((n - i - 1) % 4 == 2 && j < m - 1 && arr[i - 2][j + 1] != 0)
                res = max(res, dp[i - 2][j + 1]);
            dp[i][j] = ((res == -1) ? -1 : arr[i][j] + res);
        }
    }
    long long int result = 0;
    for (int i = 0; i < m; ++i) {
        if(dp[n - 1][i] != -1)
            result = max(result, dp[n - 1][i]);
    }
    cout << result << endl;
    return 0;
}

