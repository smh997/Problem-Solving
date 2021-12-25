/*
 * https://open.kattis.com/problems/ornaments
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
double r, h, s;
int main()
{
    while(cin>>r>>h>>s && r){
        printf("%.2lf\n", 2*sqrt(h*h-r*r) + acos(-1)*r + 2*r*asin(r/h) + (2*sqrt(h*h-r*r) + acos(-1)*r + 2*r*asin(r/h))*s/100);
    }
    return 0;
}

