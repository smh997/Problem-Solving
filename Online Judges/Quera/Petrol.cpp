/*
 * https://quera.org/problemset/82378/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    cin >> n >> k;
    cout << min(n, k + 60) * 1500 + max(n - k - 60, 0) * 3000 << endl;
}