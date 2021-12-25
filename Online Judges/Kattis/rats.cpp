/*
 * https://open.kattis.com/problems/rats
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int t, k, m;
string s;
bool flag;
unordered_set<string> se;

string build(string t){
    int n = t.length(), a, b, c;
    int car = 0;
    string res = "";
    for (int i = 0; i < n; ++i) {
        a = t[i] - '0';
        b = t[n-i-1] - '0';
        c = (a + b + car) % 10;
        res = to_string(c) + res;
        car = (a + b + car) / 10;
    }
    res = to_string(car) + res;
//    cerr << res << endl;
    sort(res.begin(), res.end());
//    cerr << res << endl;
    int it = 0;
    while(res[it] == '0'){
        it++;
    }
//    cerr << res.substr(it) << endl;
    return res.substr(it);
}

bool creeper(string t){
    if(t.length() < 8)
        return false;
    string samp1 = "1233", samp2 = "4444", samp3 = "5566", samp4 = "7777";
    int n = t.length();
    bool f = true;
    if(t.substr(0, 4) == samp1 && t.substr(n-4, 4) == samp2){
        for (int i = 4; i < n-4; ++i) {
            if(t[i] != '3'){
                f = false;
                break;
            }
        }
        if(f){
            return true;
        }
    }
    if(t.substr(0, 4) == samp3 && t.substr(n-4, 4) == samp4){
        f = true;
        for (int i = 4; i < n-4; ++i) {
            if(t[i] != '6'){
                f = false;
                break;
            }
        }
        if(f){
            return true;
        }
    }
    return false;
}

bool rep(string t){
    return se.find(t) != se.end();
}

int main()
{
    cin >> t;
    while(t--){
        cin >> k >> m >> s;
        if(s == "0"){
            if(m == 1){
                cout << k << " " << 0 << endl;
                continue;
            }
            cout << k << " R " << 2 << endl;
            continue;
        }
        flag = false;
        se.clear();
        for (int i = 1; i < m+1; ++i) {
//            cout << s << endl;
            if(creeper(s)){
                cout << k << " C " << i << endl;
                flag = true;
                break;
            }
            if(rep(s)){
                cout << k << " R " << i << endl;
                flag = true;
                break;
            }
            se.insert(s);
            if(i < m)
                s = build(s);
        }
        if(!flag){
            cout << k << " " << s << endl;
        }
    }
    return 0;
}

