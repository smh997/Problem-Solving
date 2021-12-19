/*
 * https://open.kattis.com/problems/antennaanalysis
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

long long int c, x[400003], y[400003], y2[400003], n, mx;

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    mx = LLONG_MIN;
    for (int j = 0; j < n; ++j) {
        mx = max(mx, -x[j] + c * j);
        y[j] = mx;
    }
    for (int i = 0; i < n; ++i) {
        y[i] = x[i] - (c * i) + y[i];
    }
    mx = LLONG_MIN;
    for (int j = 0; j < n; ++j) {
        mx = max(mx, x[j] + c * j);
        y2[j] = mx;
        
    }
    for (int i = 0; i < n; ++i) {
        y2[i] = -x[i] - (c * i) + y2[i];
        if (y[i] <= y2[i])
            cout << y2[i];
        else
            cout << y[i];
        if (i != n-1)
            cout << " ";
    }
    cout << endl;
    return 0;
}

