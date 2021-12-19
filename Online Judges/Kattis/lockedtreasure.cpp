/*
 * https://open.kattis.com/problems/lockedtreasure
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

long long int C[33][33];
void calc(){
    C[0][0] = 1;
    for (int i = 1; i < 31; ++i) {
        for (int j = 0; j <= i; ++j) {
            if(j==0){
                C[i][j] = 1;
                continue;
            }
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

int n, k, t;

int main()
{
    calc();
    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << C[n][k-1] << endl;
    }
    return 0;
}

