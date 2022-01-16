/*
 * https://open.kattis.com/problems/soyoulikeyourfoodhot
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
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

double aa, bb, cc;
long long int a, b, c, tmp;
set <pair<long long int, long long int>> res;

int main()
{
    cin >> cc >> aa >> bb;
    cc *= 100, aa *= 100, bb *= 100;
    cc = round(cc*100)/100;
    aa = round(aa*100)/100;
    bb = round(bb*100)/100;
    a = (int)aa, b = (int)bb, c = (int)cc;
    if(!c){
        cout << 0 << " " << 0 <<endl;
        return 0;
    }
    // get a, b, c from input
    bool revers = false;
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
        revers = true;
    }
    
    extendedEuclid(a, b);
    if(c % d){
        cout << "none" << endl;
        return 0;
    }
    x *= (c/d); y*= (c/d);
    long long int lo, hi;
    lo = (long long int) ceil(1.0 * (-x) / (b/d));
    hi = (long long int) floor(1.0 * (y) / (a/d));
    pair<int, int> pp;
    for (int i = lo; i <= hi; ++i) {
        if(revers){
            pp = {y - (a/d) * i, x + (b/d) * i};
//            if(pp.first || pp.second)
                res.insert(pp);
        }
        else{
            pp = {x + (b/d) * i, y - (a/d) * i};
//            if(pp.first || pp.second)
                res.insert(pp);
        }
    }
    for(auto vv: res){
        cout << vv.first << " " << vv.second << endl;
    }
    return 0;
}

