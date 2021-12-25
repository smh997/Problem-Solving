/*
 * https://open.kattis.com/problems/speed
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-9;

long double t, lo = 1e9, hi = 1e9, mid, d[1003], s[1003];
int n;

bool judge(long double c){
    long double ct = 0;
    for (int i = 0; i < n; ++i)
        ct += d[i] / (s[i] + c);
    return ct < t;
}

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> d[i] >> s[i];
        lo = min(lo, s[i]);
    }
    lo = -1 * lo + eps;
    while(fabsl(hi - lo) > eps){
        mid = lo + (hi - lo) / 2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << fixed << setprecision(7) << lo << endl;
    return 0;
}

