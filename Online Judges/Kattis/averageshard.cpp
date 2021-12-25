/*
 * https://open.kattis.com/problems/averageshard
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

long long int t, cs, e, scs, se, a, css[200003], res;
double avgcs, avge;

int main()
{
    cin >> t;
    while (t--) {
        scs = se = res = 0;
        cin >> cs >> e;
        for (int i = 0; i < cs; ++i)
            cin >> css[i], scs += css[i];
        for (int i = 0; i < e; ++i)
            cin >> a, se += a;
        avgcs = (double)scs / cs;
        avge = (double)se / e;
        for (int i = 0; i < cs; ++i)
            if (1.0 * (scs - css[i]) / (cs - 1) > avgcs && 1.0 * (se + css[i]) / (e + 1) > avge)
                res++;
        cout << res << endl;
    }
    return 0;
}

