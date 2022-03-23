/*
 * https://quera.org/problemset/52546/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string t; int ind = 0;
    cin >> t >> n;
    string s; int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        ind = 0;
        for (int j = 0; j < s.length(); ++j) {
            if(s[j] == t[ind])
                ind++;
            if(ind == t.length()){
                res++;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}

