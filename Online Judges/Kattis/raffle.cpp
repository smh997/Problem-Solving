/*
 * https://open.kattis.com/problems/raffle
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
double n, p;

int main()
{
    cin>>n>>p;
    int tre = n/(p-1);
    double res = tre*p/(n+1);
    for (int i = 2; i <= tre; ++i) {
        res *= (n-p+i)/(n+i);
    }
    printf("%.7f\n", res);
    return 0;
}

