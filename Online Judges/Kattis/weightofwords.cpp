/*
 * https://open.kattis.com/problems/weightofwords
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

string dp[43][1003];
int L, W;

string cdp(int i, int j){
    if(i==L && j==W)
        return "";
    else if(i==L)
        return "***";
    if(dp[i][j] != "---")
        return dp[i][j];
    string res = "";
    for (int k = 0; k < min(26, W-j); ++k) {
        res = cdp(i+1, j+k+1);
//        cout<<i<<" "<<j<<" "<<res<<endl;
        if(res != "***"){
            string s(1, char('a'+k));
            res += s;
            return dp[i][j] = res;
        }
    }
    return dp[i][j] = "***";
}

int main()
{
    cin>>L>>W;
    for (int i = 0; i <= L; ++i) {
        for (int j = 0; j <= W; ++j) {
            dp[i][j]="---";
        }
    }
    string res = cdp(0, 0);
    cout<<((res=="***")?"impossible":res)<<endl;
    return 0;
}

