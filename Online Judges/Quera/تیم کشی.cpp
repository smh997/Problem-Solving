/*
 * https://quera.org/problemset/80651/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    cout << min(a1, b1) + min(a2, b2) + min(a3, b3) << endl;
}