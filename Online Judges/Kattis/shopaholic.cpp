/*
 * https://open.kattis.com/problems/shopaholic
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int p[n];
    for (int i = 0; i < n; ++i)
        cin>>p[i];
    sort(p, p+n, greater<int>());
    long long int res = 0;
    for (int i = 0; i < n/3; ++i) {
        res += p[i*3+2];
    }
    cout<<res<<endl;
    return 0;
}

