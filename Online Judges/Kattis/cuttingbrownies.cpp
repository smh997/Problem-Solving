/*
 * https://open.kattis.com/problems/cuttingbrownies
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int p[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        string s;
        cin >> m >> n >> s;
        int l = upper_bound(p, p + 10, m) - p;
        int r = upper_bound(p, p + 10, n) - p;
        if(l == r)
            cout << s << " cannot win" << endl;
        else if(l > r){
            if(s == "Vicky")
                cout << s << " can win" << endl;
            else
                cout << s << " cannot win" << endl;
        }
        else{
            if(s == "Vicky")
                cout << s << " cannot win" << endl;
            else
                cout << s << " can win" << endl;
        }
    }
}