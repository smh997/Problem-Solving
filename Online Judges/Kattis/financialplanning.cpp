/*
 * https://open.kattis.com/problems/financialplanning
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
ll n, m;
ll p[100003], c[100003];

bool observe(ll days){
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        if(s > 1e9)
            break;
        s += ((days * p[i] - c[i] < 0) ? 0 : days * p[i] - c[i]);
    }
    return s >= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> p[i] >> c[i];
    ll lo = 0, hi = 2 * 1e9, mid;
    while(hi > lo){
        mid = (hi + lo) / 2;
        if (observe(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << endl;
    return 0;
}

