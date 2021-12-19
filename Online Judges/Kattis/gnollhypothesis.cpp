/*
 * https://open.kattis.com/problems/gnollhypothesis
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, k;
double s[1003];
double psum[1003];
double f[1003];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    cout << fixed << setprecision(7);
    if(n==1){
        cout << s[0] << endl;
        return 0;
    }
    if(k==1){
        for (int i = 0; i < n; ++i) {
            cout << (100.0)/n << " ";
        }
        cout << endl;
        return 0;
    }
    for (int i = n; i < 2*n; ++i) {
        s[i] = s[i-n];
    }
    psum[0] = s[0];
    for (int i = 1; i < 2*n; ++i) {
        psum[i] = psum[i-1] + s[i];
    }
    f[0] = double(k*(k-1)) / (n * (n-1));
    for (int i = 0; i < n-k; ++i) {
        f[i+1] = (double(n-i-k)/(n-i-2))*f[i];
    }
    double p;
    for (int i = n; i < 2*n; ++i) {
        double res = 0;
        for (int d = 0; d <= n-k; ++d) {
            p = psum[i] - ((i-d==0)?0:psum[i-d-1]);
            res += p * f[d];
        }
        cout << res << " ";
    }
    cout << endl;
    return 0;
}

