/*
 * https://open.kattis.com/problems/palindromesubstring
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int dp[1003][1003];
set<string> res;
string s;
bool cdp(int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == j || j == i-1)
        return true;
    dp[i][j] = (s[i] == s[j]) && cdp(i+1, j-1);
    if(dp[i][j])
        res.insert(s.substr(i, j-i+1));
    return dp[i][j];
}

int main()
{
    int n;
    while(cin >> s){
        res.clear();
        n = s.length();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                cdp(i, j);
            }
        }
        for(auto ss : res){
            cout << ss << endl;
        }
        cout << endl;
    }
    return 0;
}

