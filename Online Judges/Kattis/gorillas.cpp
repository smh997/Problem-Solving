/*
 * https://open.kattis.com/problems/gorillas
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

double x11, y11, x22, y22;
int n;
double xo[1003], yo[1003];

bool judge(double a, double b, double c){
    for(int i = 0; i < n; i++){
        double y = a * xo[i] * xo[i] + b * xo[i] + c;
        if(y < yo[i])
            return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> x11 >> y11 >> x22 >> y22;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> xo[i] >> yo[i];
        if(n == 0){
            cout << max(y11, y22) << endl;
            continue;
        }
        double lo = max(y11, y22), hi = 1e8;
        while(fabs(lo - hi) > 1e-7){
            double h = (lo + hi) / 2;
            double d = y11 - y22;
            double e = x11 * x11 - x22 * x22;
            double f = x11 - x22;
            double A = 4 * f * f * x11 * x11 - 4 * f * e * x11 + e * e;
            double B = 4 * f * d * x11 + 4 * h * f * f - 2 * d * e - 4 * f * f * y11;
            double C = d * d;
            double a = (-B - sqrt(B * B - 4 * A * C)) / (2 * A);
            double b = (d - a * e) / f;
            double c = h + (b * b) / (4 * a);
            if(judge(a, b, c))
                hi = h;
            else
                lo = h;
        }
        cout << fixed << setprecision(6) << lo << endl;
    }
}