/*
 * https://open.kattis.com/problems/primesieve
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, a, res = 0;
    cin >> n >> q;
    vector<bool> pFlags(n+1, true);
    pFlags[0] = pFlags[1] = false;
    for (long long int i = 2; i < (int)sqrt(n); ++i) {
        if(pFlags[i]){
            for (long long int j = i * i; j <= n; j += i) {
                pFlags[j] = false;
            }
            res++;
        }
    }
    for (int i = (int)sqrt(n)+1; i <= n; ++i) {
        if(pFlags[i])
            res++;
    }
    cout << res << endl;
    for (int i = 0; i < q; ++i) {
        cin >> a;
        cout << pFlags[a] << endl;
    }
    
    return 0;
}

