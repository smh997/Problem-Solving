/*
 * https://open.kattis.com/problems/orchard
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

double dp[5][5][5][5][10];

double cdp(int r, int g, int b, int y, int s){
    if(s == 0){
        return 0;
    }
    if(r == g && r == b && r == y && r == 0){
        return 1;
    }
    if(dp[r][g][b][y][s] != -1){
        return dp[r][g][b][y][s];
    }
    int maxx = (max(r, max(b, max(g, y))));
    int cnt2 = 0;
    double ans = 0;
    if(r>0){
        ans += cdp(r-1, g, b, y, s);
        cnt2++;
    }
    if(b>0){
        ans += cdp(r, g, b-1, y, s);
        cnt2++;
    }
    if(g>0){
        ans += cdp(r, g-1, b, y, s);
        cnt2++;
    }
    if(y>0){
        ans += cdp(r, g, b, y-1, s);
        cnt2++;
    }
    if(s>0){
        ans += cdp(r, g, b, y, s-1);
        cnt2++;
    }
    double dd = 0; int cnt = 0;
    cnt2++;
    if(r == maxx){
        dd += cdp(r-1, g, b, y, s);
        cnt++;
    }
    if(b == maxx){
        dd += cdp(r, g, b-1, y, s);
        cnt++;
    }
    if(g == maxx){
        dd += cdp(r, g-1, b, y, s);
        cnt++;
    }
    if(y == maxx){
        dd += cdp(r, g, b, y-1, s);
        cnt++;
    }
    ans += (dd/cnt);
    return dp[r][g][b][y][s] = ans/cnt2;
}

int R, G, B, Y, S;

int main()
{
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            for (int k = 0; k < 5; ++k)
                for (int l = 0; l < 5; ++l)
                    for (int o = 0; o < 9; ++o)
                        dp[i][j][k][l][o] = -1;
    cin >> R >> G >> B >> Y >> S;
    cout << fixed << setprecision(6) << cdp(R, G, B, Y, S) << endl;
    return 0;
}

