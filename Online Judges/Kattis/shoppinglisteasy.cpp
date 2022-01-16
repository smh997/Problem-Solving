/*
 * https://open.kattis.com/problems/shoppinglisteasy
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> lis[103];

int main()
{
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> s;
            lis[i].push_back(s);
        }
        sort(lis[i].begin(), lis[i].end());
    }
    bool flag = true;
    vector<string> ans;
    for (int j = 0; j < m; ++j) {
        flag = true;
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(lis[i].begin(), lis[i].end(), lis[0][j]);
//            cout << it - lis[i].begin() << " " << lis[i][it-lis[i].begin()] << endl;
            if(lis[i][it-lis[i].begin()] != lis[0][j]){
                flag = false;
                break;
            }
        }
        if(flag){
            ans.push_back(lis[0][j]);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}

