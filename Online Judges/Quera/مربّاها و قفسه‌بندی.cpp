/*
 * https://quera.org/problemset/20250/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){    
    int n;
    cin >> n;
    set<ll> a;
    set<pair<ll, ll>> b;
    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        a.insert(x);
        b.insert(make_pair(x, y));
    }
    n = b.size();
    int m = n - a.size();
    cout << (((n * (n + 1)) / 2) - ((m * (m + 1)) / 2) + m) << endl;
}