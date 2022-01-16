/*
 * https://codeforces.com/contest/1455/problem/B
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int t, x;
long long int step, b;

int main()
{
    cin >> t;
    while(t--){
        cin >> x;
        step = sqrt(2*x)-1;
        while(step*(step+1) < 2*x){
            step++;
        }
        b = step*(step+1)/2;
        cerr << step << " " << b << endl;
        if(b == x+1){
            cout << step + 1 << endl;
            continue;
        }
        cout << step << endl;
    }
    return 0;
}
 