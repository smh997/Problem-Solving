/*
 * https://open.kattis.com/problems/maximumrent
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int a, b, m, s;

int main(){
    cin >> a >> b >> m >> s;
    int x, y;
    if(a >= b){
        x = m - 1;
        for(int i = x; i >= 1; i--){
            y = m - i;
            if(2 * i + y >= s){
                x = i;
                break;
            }
        }
        cout << a * x + b * y << endl;
    }
    else{
        y = m - 1;
        for(int i = y; i >= 1; i--){
            x = m - i;
            if(2 * x + i >= s){
                y = i;
                break;
            }
        }
        cout << a * x + b * y << endl;
    }
}