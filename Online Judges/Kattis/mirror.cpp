/*
 * https://open.kattis.com/problems/mirror
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int t, r, c;
char g[23][23];

int main()
{
    cin>>t;
    for (int i = 1; i <= t; ++i) {
        cin>>r>>c;
        for (int rr = 0; rr < r; ++rr) {
            for (int cc = 0; cc < c; ++cc) {
                cin>>g[r-rr-1][c-cc-1];
            }
        }
        cout<<"Test "<<i<<endl;
        for (int rr = 0; rr < r; ++rr) {
            for (int cc = 0; cc < c; ++cc) {
                cout<<g[rr][cc];
            }
            cout<<endl;
        }
        
    }
    return 0;
}

