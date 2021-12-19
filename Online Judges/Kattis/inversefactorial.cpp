/*
 * https://open.kattis.com/problems/inversefactorial
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int main(){
    string s;
    cin >> s;
    if(s.size() <= 7){
        int fact = stoi(s);
        int n = 2, d = 1;
        while(fact != 1){
            fact /= n;
            n++, d++;
        }
        cout << d << endl;
        return 0;
    }
    double lg = 0;
    for(int i = 2; i <= 1000000; i++){
        lg += log10(i);
        m[int(ceil(lg) + 1e-9)] = i;
    }
    cout << m[s.size()] << endl;
}
