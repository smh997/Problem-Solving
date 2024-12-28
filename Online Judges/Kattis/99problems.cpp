/*
 * https://open.kattis.com/problems/99problems
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, lg, pw;

int main(){
    cin >> n;
    if(n < 99)
        cout << 99 << endl;
    else{
        if (n - ((n / 100) * 100 - 1) < ((n / 100 + 1) * 100 - 1) - n){
            cout << ((n / 100) * 100 - 1) << endl;
        }
        else{
            cout << ((n / 100 + 1) * 100 - 1) << endl;
        }
    }

    return 0;
}