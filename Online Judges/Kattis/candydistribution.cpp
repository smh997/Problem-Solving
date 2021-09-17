/*
 * https://open.kattis.com/problems/candydistribution
 * Author: https://github.com/smh997/
 */

#include <iostream>

using namespace std;

// Extended Euclid: Solving Linear Diophantine Equation
// ax + by = c has no integral solutions if gcd(a, b) | c is not true
// calculate x0, y0 by this algorithm
// then: x = x0 + (b/gcd(a, b))n, y = y0 − (a/gcd(a, b))n
long long int x, y, d; // d = gcd(a, b)
void extendedEuclid(long long int a, long long int b) {
    if (b == 0){ // base case
        x = 1;
        y = 0; 
        d = a;
        return;
    }
    extendedEuclid(b, a % b); // similar as the original gcd
    long long int x1 = y;
    long long int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}


// work to find x in: a.x ≡ 1 mod m
void modularInverse(long long int a, long long int m){
    extendedEuclid(a, m);
    if (d != 1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        x = (x % m + m) % m;
        cout << x << endl;
    }    
}


int main()
{
    long long int n, c, k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k >> c;
        if(k == 1){
            cout << ((c==1)?2:1) << endl;
        }
        else if (c==1){
            cout << k+1 <<endl;
        }
        else
            modularInverse(c, k);
    }
    return 0;
}

