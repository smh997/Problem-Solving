/*
 * https://open.kattis.com/problems/amsterdamdistance
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int n, m, ax, ay, bx, by;
double r;

int main()
{
    cin>>m>>n>>r;
    cin>>ax>>ay>>bx>>by;
    double mi = ay*r/n + by*r/n;
    for (int i = 1; i <= ay; ++i)
        mi = min(mi, abs(i-by)*r/n + abs(i-ay)*r/n + i*r/n*2*acos(-1)*abs(ax-bx)/(2*m));
    printf("%0.7lf\n", mi);
    return 0;
}

