/*
 * https://open.kattis.com/problems/stringfactoring
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const int max_size = 203;
int dp [max_size][max_size];
string s;

int cdp(int l, int r){
    if(dp[l][r] != -1)
        return dp[l][r];
    if(l == r)
        return 1;
    int leng = r-l+1, ans = leng;
    for (int i = l; i < r; ++i)
        ans = min(ans, cdp(l, i) + cdp(i+1, r));
    for (int i = 1; i < leng; ++i) {
        if(leng % i == 0){
            bool flag = true;
            for (int k = i; k < leng; ++k) {
                if(s[l+k] != s[l+k%i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans = min(ans, cdp(l, l+i-1));
            }
        }
    }
    return dp[l][r] = ans;
}

int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
        for (int j = 0; j < s.length(); ++j)
            dp[i][j] = -1;
    cout << cdp(0, s.length()-1) << endl;
    return 0;
}

