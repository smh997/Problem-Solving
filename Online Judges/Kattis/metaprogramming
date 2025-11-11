/*
 * https://open.kattis.com/problems/metaprogramming
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    string cmd;
    map<string, int> dict;
    while (cin >> cmd) { 
        if (cmd == "define") {
            int val;
            string name;
            cin >> val >> name;
            dict[name] = val;
        } else if (cmd == "eval") {
            string x, op, y;
            cin >> x >> op >> y;
            if (dict.count(x) == 0 || dict.count(y) == 0) {
                cout << "undefined" << endl;
            } 
            else {
                int a = dict[x], b = dict[y];
                if (op == "<") 
                    cout << (a < b ? "true" : "false") << endl;
                else if (op == ">") 
                    cout << (a > b ? "true" : "false") << endl;
                else 
                    cout << (a == b ? "true" : "false") << endl;
            }
        }
    }
}
