/*
 * https://quera.org/problemset/7609/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int res = 1;
    for (int i = 0; i < s.length() - 1; ++i) {
        if(s[i] == s[i + 1])
            res++;
        else{
            if(res % 2 == 1){
                cout << "bad" << endl;
                return 0;
            }
            res = 1;
        }
    }
    if(s[s.length() - 2] != s[s.length() - 1])
        cout << "bad" << endl;
    else
        cout << "khoob" << endl;

    return 0;
}
