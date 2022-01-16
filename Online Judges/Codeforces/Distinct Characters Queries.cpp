/*
 * https://codeforces.com/contest/1234/problem/D
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100003

set<int> s[30];

int main()
{
    string ss; char ch;
    int fi, se, q, typ, res, n;
    cin >> ss;
    n = ss.length();
    for (int i = 0; i < n; ++i) {
        s[ss[i]-'a'].insert(i);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> typ >> fi;fi--;
        if(typ == 1){
            cin >> ch;
            s[ss[fi]-'a'].erase(fi);
            ss[fi] = ch;
            s[ch-'a'].insert(fi);
        }
        else{
            cin >> se;se--;
            res = 0;            
            for (int i = 0; i < 26; ++i) {
                auto a = s[i].lower_bound(fi);
                if(a != s[i].end() && *a <= se){
                    res++;
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}
 