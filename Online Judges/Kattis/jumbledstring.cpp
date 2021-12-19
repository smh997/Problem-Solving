/*
 * https://open.kattis.com/problems/jumbledstring
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>

using namespace std;

double n_(double a){
    return (1 + sqrt(1 + 8 * a)) / 2;
}


int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == 0 && b == 0 && c == 0 && d == 0){
        cout << "0" << endl;
        return 0;
    }
    if(a != 0 && d == 0 && b == 0 && c == 0){
        double n__ = n_(a);
        if(n__ != int(n__)){
            cout << "impossible" << endl;
            return 0;
        }
        int n = n__;
        while(n--)
            cout << "0";
        cout << endl;
        return 0;
    }
    if(a == 0 && d != 0 && b == 0 && c == 0){
        double n__ = n_(d);
        if(n__ != int(n__)){
            cout << "impossible" << endl;
            return 0;
        }
        int n = n__;
        while(n--)
            cout << "1";
        cout << endl;
        return 0;
    }
    double n__ = n_(a);
    if(n__ != int(n__)){
        cout << "impossible" << endl;
        return 0;
    }
    int n = n__;
    double m__ = n_(d);
    if(m__ != int(m__)){
        cout << "impossible" << endl;
        return 0;
    }
    int m = m__;
    if((b + c) % n != 0){
        cout << "impossible" << endl;
        return 0;
    }
    if((b + c) / n != m){
        cout << "impossible" << endl;
        return 0;
    }
    vector<int> ones;
    ones.assign(n+1, 0);
    if(b / n != 0){
        ones[n] += b / n;
        b %= n;
    }
    if(b != 0){
        ones[b]++;
        c -= (n - b);
    }
    ones[0] += c / n;
    for(int i = 0; i < n; i++){
        while(ones[i]--) cout << "1";
        cout << "0";
    }
    while(ones[n]--) cout << "1";
    cout << endl;
}