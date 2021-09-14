/*
 * https://open.kattis.com/problems/allaboutthatbase
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

long long int u = (1ll << 32) - 1;

vector<int> digits;
long long int proc(string s, int base){
    digits.clear();
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] >= 'a' && s[i] <= 'z')
            digits.push_back(s[i] - 'a' + 10);
        else digits.push_back(s[i] - '0');
    }
    long long int ans = 0;
    if(base == 1){
        for(int d : digits){
            if(d != 1)
                return -1;
            ans += 1;
            if(ans > u)
                return -1;
        } 
    }
    else{
        long long int p = 1;
        for(int d : digits){
            if(d >= base)
                return -1;
            ans += d * p;
            if(ans > u)
                return -1;
            p *= base;
        }
    }
    if(ans >= 1 && ans <= u)
        return ans;
    return -1;
}

inline char ib(int b){
    if(b == 36)
        return '0';
    if(b < 10)
        return b + '0';
    return 'a' + (b - 10);
}

string op1, op2, op3;
char o1, o2; 

void solve(){
    bool valid = false;
    for(int b = 1; b <= 36; b++){
        long long int a = proc(op1, b);
        if(a == -1)
            continue;
        long long int bb = proc(op2, b);
        if(bb == -1)
            continue;
        long long int c = proc(op3, b);
        if(c == -1)
            continue;
        if(o1 == '+' && a + bb == c)
            cout << ib(b), valid = true;
        if(o1 == '*' && a * bb == c)
            cout << ib(b), valid = true;
        if(o1 == '-' && a - bb == c)
            cout << ib(b), valid = true;
        if(o1 == '/' && a % bb == 0 && a / bb == c)
            cout << ib(b), valid = true;
    }
    if(!valid)
        cout << "invalid";
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> op1 >> o1 >> op2 >> o2 >> op3;
        solve();
    }   
}