/*
 * https://open.kattis.com/problems/nafnagift
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, m;
string a, b;
int dp[1003][1003];
pair<int, int> nxt[1003][1003];

int cdp(int i, int j){
    if(dp[i][j] != INT_MAX)
        return dp[i][j];
    if(i == n && j == m)
        return 0;
    int ans = INT_MAX, c1, c2;
    if(i == n){
        if(ans > 1 + cdp(i, j+1)){
            ans = 1 + cdp(i, j+1);
            nxt[i][j] = {i, j+1};
        }
    }
    else if (j == m){
        if(ans > 1 + cdp(i+1, j)){
            ans = 1 + cdp(i+1, j);
            nxt[i][j] = {i+1, j};
        }
    }
    else if(a[i] == b[j]){
        if(ans > 1 + cdp(i+1, j+1)){
            ans = 1 + cdp(i+1, j+1);
            nxt[i][j] = {i+1, j+1};
        }
    }
    else{
        c1 = cdp(i+1, j);
        c2 = cdp(i, j+1);
        if(ans > 1 + c1){
            ans = 1 + c1;
            nxt[i][j] = {i+1, j};
        }
        if(ans > 1 + c2){
            ans = 1 + c2;
            nxt[i][j] = {i, j+1};
        }
    }
    return dp[i][j] = ans;
}


int main(){
    cin >> a >> b;
    n = a.length();
    m = b.length();

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = INT_MAX;
    
    cdp(0, 0);
    pair<int, int> cur;
    int i = 0, j = 0;
    string res = "";
    while(i != n || j != m){
        if(nxt[i][j].first > i)
            res += a[i];
        else
            res += b[j];
        cur = nxt[i][j];
        i = cur.first;
        j = cur.second;
    }
    cout << res << endl;

    return 0;
}