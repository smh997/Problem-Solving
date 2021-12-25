/*
 * https://open.kattis.com/problems/password
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

double arr[503];
int n;

int main()
{
    cout << fixed << setprecision(5);
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s >> arr[i];
        arr[i] = arr[i] * 10000;
    }
    sort(arr, arr + n, greater<double>());
    double res;
    for (int i = 0; i < n; ++i) {
        res += (i+1) * arr[i];
    }
    cout << res/10000 << endl;
    return 0;
}

