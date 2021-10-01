/*
 * https://open.kattis.com/problems/fencebowling
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

// Fence Bowling

int k;
double w, l;

int judge(double a){
    double le = (w / 2) * tan(a);
    a = atan(2 * tan(a));
    for(int i = 0; i < k-2; i++){
        le += w * tan(a);
        a = atan(2 * tan(a));
    }
    if(le >= l)
        return 1;
    le += w * tan(a);
    if(le <= l)
        return -1;
    double toropche = w - (le - l) / tan(a);
    if(fabs(toropche - w/2) < 0.00000001)
        return 0;
    if(toropche > w/2)
        return -1;
    return 1;
}

int main(){
    cin >> k >> w >> l;
    k++;
    double start = 0, end = 1.57079632679489661923, mid;
    while(fabs(end - start) > 0.00000001){
        mid = (start + end) / 2;
        int r = judge(mid);
        if(r == 0)
            break;
        else if(r == 1)
            end = mid;
        else start = mid;
    }
    cout << fixed << setprecision(10);
    cout << mid * 180 / 3.14159265358979323846 << endl;
}