/*
 * https://quera.org/problemset/80645/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    cout << (min(n, m) / max(a, b) + ((min(n, m) % max(a, b)) ? 1 : 0)) << endl;
}