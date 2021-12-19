/*
 * https://open.kattis.com/problems/homework
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

string s, s1, s2;
int n, n1, n2;

int dp[5003][5003];

int cdp(int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == n1 && j == n2)
        return dp[i][j] = 1;
    bool ans = 0;
    int k = i + j;
    if(i < n1 && s[k] == s1[i])
        ans = ans || cdp(i+1, j);
    if(j < n2 && s[k] == s2[j])
        ans = ans || cdp(i, j+1);
    return dp[i][j] = ans;
}

int main(){
    for(int i = 0; i < 5003; i++)
        for(int j = 0; j < 5003; j++)
            dp[i][j] = -1;
    cin >> s >> s1 >> s2;
    n = s.size(), n1 = s1.size(), n2 = s2.size();
    cout << (cdp(0, 0) ? "yes" : "no") << endl;
}