/*
 * https://open.kattis.com/problems/jewelrybox
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, tmp;
    double lo , hi, x, y, p, q, resp, resq;
    cin>>t;
    while(t--){
        cin>>x>>y;
        if(x>y){
            tmp = x;
            x = y;
            y = tmp;
        }
        lo = 0; hi = x/2;
        while(hi-lo>0.00000001){
            p = lo + (hi-lo)/3;
            q = lo + (hi-lo)*2/3;
            resp = p*(x-2*p)*(y-2*p);
            resq = q*(x-2*q)*(y-2*q);
            if(resp>resq)
                hi = q;
            else
                lo = p;
        }
        printf("%.7lf\n", lo*(x-2*lo)*(y-2*lo));
    }
    return 0;
}

