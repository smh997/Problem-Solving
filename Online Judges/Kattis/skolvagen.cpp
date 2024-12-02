/*
 * https://open.kattis.com/problems/skolvagen
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, dp[1003][3];
string cross;

int cdp(int i, int side){
    if(i == n)
        return side;
    if(dp[i][side] != -1)
        return dp[i][side];
    int toward = (cross[i] == 'N')?0:((cross[i] == 'S')?1:2);
    int ans = 10000;
    if(toward == 2)
        ans = min(1 + cdp(i+1, side), 2 + cdp(i+1, 1-side));
    else if (toward == side)
        ans = min(1 + cdp(i+1, side), 1 + cdp(i+1, 1-side));
    else
        ans = min(cdp(i+1, side), 2 + cdp(i+1, 1-side));
    // cerr << i << " " << side << " " << ans << endl;
    return dp[i][side] = ans;
}

int main(){
    cin >> cross;
    n = cross.length();
    for (int i = 0; i < n; i++)
        dp[i][0] = dp[i][1] = -1;
    cout << cdp(0, 0) << endl;
    
    return 0;
}