/*
 * https://open.kattis.com/problems/election
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-8

long long int C[53][53];
void calc(){
    C[1][0] = C[1][1] = 1;
    for (int i = 2; i < 51; ++i) {
        for (int j = 0; j < 51; ++j) {
            if(j==0){
                C[i][j] = 1;
                continue;
            }
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

int t, n, v1, v2, w, win, rem, need;
double s;
bool flag;

int main()
{
    calc();
    cin >> t;
    while(t--){
        cin >> n >> v1 >> v2 >> w;
        win = n/2 + 1;
        if(v1 >= win){
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
            continue;
        }
        else if(v2 >= win){
            cout << "RECOUNT!" << endl;
            continue;
        }
        rem = n - v1 - v2;
        need = win - v1;
        s = 0;
        for (int i = need; i <= rem; ++i) {
            s += C[rem][i];
        }
        if(s == 0){
            cout << "RECOUNT!" << endl;
            continue;
        }
        s *= 100;
        flag = true;
        while(rem--){
            s /= 2;
            if(s < (double)w || fabs(s-(1.0*w)) < EPS){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
        }
        else{
            cout << "PATIENCE, EVERYONE!" << endl;
        }
    }
    return 0;
}

