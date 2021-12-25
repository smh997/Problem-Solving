/*
 * https://open.kattis.com/problems/reconnaissance
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double d = 1e-4;
    int arr[n][2];
    for (int i = 0; i < n; ++i)
        cin>>arr[i][0]>>arr[i][1];
    double lo = 0, hi= 200001, s, e, c, minp, maxp, vals, vale;
    while(hi-lo>d){
        s = lo + (hi-lo)/3;
        e = lo + (hi-lo)*2/3;
        minp = 1e12;
        maxp = -1e12;
        for (int i = 0; i < n; ++i) {
            c = arr[i][0]+arr[i][1]*s;
            minp = min(minp, c);
            maxp = max(maxp, c); 
        }
        vals = maxp - minp;
        minp = 1e12;
        maxp = -1e12;
        for (int i = 0; i < n; ++i) {
            c = arr[i][0]+arr[i][1]*e;
            minp = min(minp, c);
            maxp = max(maxp, c); 
        }
        vale = maxp - minp;
        if(vals<vale)
            hi = e;
        else
            lo = s;
    }
    minp = 1e12;
    maxp = -1e12;
    for (int i = 0; i < n; ++i) {
        c = arr[i][0]+arr[i][1]*lo;
        minp = min(minp, c);
        maxp = max(maxp, c); 
    }
    vale = maxp - minp;
    printf("%.4lf\n", vale);
    return 0;
}

