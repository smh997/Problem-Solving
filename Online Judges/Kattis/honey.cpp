/*
 * https://open.kattis.com/problems/honey
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int t, n, dp[100][100][17];
pair<int, int> direction[6] = {
    {2, 0}, {1, 1}, {-1, 1}, {-2, 0}, {-1, -1}, {1, -1}
};

void init(){
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            for (int s = 0; s < 15; s++)
                dp[i][j][s] = -1;
    dp[50][50][0] = 1;
}

int cdp(int i, int j, int step){
    if (step < 0)
        return 0;
    
    if (dp[i][j][step] != -1)
        return dp[i][j][step];
    
    int ans = 0;
    for(auto d: direction)
        ans += cdp(i + d.first, j + d.second, step - 1);
    
    return dp[i][j][step] = ans;
}

int main(){
    cin >> t;
    while (t--){
        init();
        cin >> n;
        cout << cdp(50, 50, n) << endl;
    }
    
    return 0;
}