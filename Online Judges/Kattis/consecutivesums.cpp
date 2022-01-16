/*
 * https://open.kattis.com/problems/consecutivesums
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int t;
long long int n, s, rem;
bool flag;
int main()
{
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        int st = 2;
        while(true){
            s = st * (st-1) / 2;
            rem = n - s;
            if(rem <= 0){
                cout << "IMPOSSIBLE" << endl;
                break;
            }
            if(!(rem % st)){
                cout << n << " = ";
                for (int i = 0; i < st; ++i) {
                    cout << i+(rem/st) << ((i==st-1)?"\n":" + ");
                }
                break;
            }
            st++;
        }
    }
    
    return 0;
}

