/*
 * https://open.kattis.com/problems/multiplicationgame
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int t, n;
string s, d;
map<int, int> factors;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> s;
        if(s == "Alice")
            d = "Bob";
        else
            d = "Alice";
        factors.clear();
        while(n > 1){
            int up = sqrt(n);
            int factor = n;
            for(int i = 2; i <= up; i++)
                if(!(n % i)){
                    factor = i;
                    break;
                }
            factors[factor]++;
            if(factors.size() >= 3)
                break;
            n /= factor;
        }
        if(factors.size() >= 3)
            cout << "tie" << endl;
        else if(factors.size() == 2){
            int u = factors.begin()->second, v = next(factors.begin())->second;
            if(abs(u - v) == 1)
                cout << s << endl;
            else if(u == v)
                cout << d << endl;
            else
                cout << "tie" << endl;
        }
        else{
            int k = factors.begin()->second;
            if(k % 2)
                cout << s << endl;
            else
                cout << d << endl;
        }
    }
}