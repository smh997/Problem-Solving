/*
 * https://codeforces.com/contest/1457/problem/C
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, p, k, x, y, t, mi, su;
string s;
int plats[100003];

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> p >> k >> s >> x >> y;p--;
        for (int i = n-1; i >= 0; --i) {
            plats[i] = (s[i]-'0') + ((i+k<=n-1)?plats[i+k]:0);
//            cout << i << " " << plats[i] << endl;
        }
//        cout << endl;
        mi = INT_MAX;
        su = 0;
        for (int i = p; i-p < n-p; ++i) {
            su = (i-p)*y + ((((n-i-1)/k + 1) - plats[i] > 0)?((n-i-1)/k + 1) - plats[i]:0) * x;
            mi = min(mi, su);
//            cout << i << " " << su << endl;
        }
        cout << mi << endl;
    }
    return 0;
}
 