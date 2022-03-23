/*
 * https://quera.org/problemset/69898/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

string s, p;
bool flag = true;
int cnt = 0, c;
map<int, int> mp, tmp;
int main()
{
    cin >> s >> p;
    if(s.length() < p.length()){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        mp[i] = 0;
    }
    for (int i = 0; i < p.length(); ++i) {
        mp[(int)p[i]]++;
    }
    for (int j = 0; j < s.length() - p.length() + 1; ++j) {
        for (int i = 'a'; i <= 'z'; ++i) {
            tmp[i] = 0;
        }
        c = 0;
        for (int k = j; k < j + p.length(); ++k) {
            if(s[k] == '?'){
                c++;
                continue;
            }
            tmp[(int)s[k]]++;
        }
        flag = true;
        for (int i = 'a'; i <= 'z'; ++i) {
            if(tmp[i] == mp[i]){
                continue;
            }
            if(tmp[i] > mp[i]){
                flag = false;
                break;
            }
            else if(c >= mp[i] - tmp[i]){
                c -= mp[i] - tmp[i];
            }
            else{
                flag = false;
                break;
            }   
        }
        if(flag)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}

