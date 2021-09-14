/*
 * https://open.kattis.com/problems/bobby
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

long long int C[13][13];

void calc(){
    C[0][0] = 1;
    for (int i = 1; i < 11; ++i) {
        for (int j = 0; j <= i; ++j) {
            if(j == 0){
                C[i][j] = 1;
                continue;
            }
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

int r, s, x, y, w, n;
double res;
int main()
{
    calc();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> r >> s >> x >> y >> w;
        res = 0;
        for (int i = x; i <= y; ++i) {
            res += C[y][i] * (1.0 * pow((s-r+1), i) / pow(s, i)) * (1.0 * pow(r-1, y-i) / pow(s, y-i)) * w;
        }
        if(res > 1){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
    return 0;
}

