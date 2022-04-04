/*
 * https://open.kattis.com/problems/haiku
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
set<string> syllables;
string s[3], sy;
int dp[103][10][3];

int cdp(int i, int target_syllable, int s_i){
    if (s[s_i][i] == ' ')
        i++;
    if (target_syllable < 0)
        return 0;
    if (dp[i][target_syllable][s_i] != -1)
        return dp[i][target_syllable][s_i];
    if (target_syllable == 0 && i == s[s_i].length())
        return dp[i][target_syllable][s_i] = 1;
    
    string tmp (1, s[s_i][i]);
    auto it = syllables.lower_bound(tmp);
    int res = 0;
    
    for (auto sy_i = it; sy_i != syllables.end(); sy_i++){
        sy = *sy_i;
        if(res || sy[0] != s[s_i][i])
            break;
        int len = sy.length();
        if (sy == s[s_i].substr(i, len)){
            res = max(res, cdp(i + len, target_syllable - 1, s_i));
        }
    }
    return dp[i][target_syllable][s_i] = res;
}

int main(){
    cin >> n;
    for (int i = 0; i < 103; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 3; k++)
                dp[i][j][k] = -1;
    
    for (int i = 0; i < n; i++){
        cin >> sy;
        syllables.insert(sy);
    }
    getline(cin, s[0]);
    getline(cin, s[0]);
    getline(cin, s[1]);
    getline(cin, s[2]);
    
    if (count(s[0].begin(), s[0].end(), ' ') > 4 || count(s[1].begin(), s[1].end(), ' ') > 6 || count(s[2].begin(), s[2].end(), ' ') > 4 || !(cdp(0, 5, 0) && cdp(0, 7, 1) && cdp(0, 5, 2)))
        cout << "come back next year" << endl;
    else
        cout << "haiku" << endl;

    return 0;
}