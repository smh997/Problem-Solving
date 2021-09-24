/*
 * https://open.kattis.com/problems/character
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n <= 1)
        cout << 0 << endl;
    else
        cout << (1 << n) - n - 1 << endl;
}