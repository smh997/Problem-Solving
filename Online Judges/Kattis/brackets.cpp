/*
 * https://open.kattis.com/problems/brackets
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

// Brackets

string s, r;
int n;

struct interval{
    int open, close;
} is[5003][5003], ir[5003][5003];

int main(){
    cin >> s;
    n = s.size();
    r = "";
    for(int i = 0; i < n; i++)
        r += (s[i] == '(') ? ')' : '(';
    for(int i = 0; i < n; i++){
        int open = 0, close = 0;
        for(int j = i; j < n; j++){
            if(s[j] == '(')
                open++;
            else{
                if(open)
                    open--;
                else
                    close++;
            }
            is[i][j].open = open, is[i][j].close = close;
        }
    }
    for(int i = 0; i < n; i++){
        int open = 0, close = 0;
        for(int j = i; j < n; j++){
            if(r[j] == '(')
                open++;
            else{
                if(open)
                    open--;
                else
                    close++;
            }
            ir[i][j].open = open, ir[i][j].close = close;
        }
    }
    if(!is[0][n-1].open && !is[0][n-1].close){
        cout << "possible" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++){
            if(!i){
                if(j == n-1){
                    if(!ir[0][n-1].open && !ir[0][n-1].close){
                        cout << "possible" << endl;
                        return 0;
                    }
                }
                else{
                    if(!ir[0][j].close && !is[j+1][n-1].open && ir[0][j].open == is[j+1][n-1].close){
                        cout << "possible" << endl;
                        return 0;
                    }
                }
            }
            else{
                if(j == n-1){
                    if(!is[0][i-1].close && !ir[i][n-1].open && is[0][i-1].open == ir[i][n-1].close){
                        cout << "possible" << endl;
                        return 0;
                    }
                }
                else{ // ( )( )
                    if(!is[0][i-1].close && !is[j+1][n-1].open){
                        int a = is[0][i-1].open, b = ir[i][j].close, c = ir[i][j].open, d = is[j+1][n-1].close;
                        if(a + c == b + d && a >= b){
                            cout << "possible" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    cout << "impossible" << endl;
}