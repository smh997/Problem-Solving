/*
 * https://open.kattis.com/problems/leftandright
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

list<int> perm;
list<int>::iterator lit = perm.end();

void action(char c, int i){
    if(c == 'R'){
        perm.push_back(i);
        lit = perm.end();
    }
    else if(c == 'L'){
        if(lit == perm.end()){
            advance(lit, -1);
        }
        perm.insert(lit, i);
        advance(lit, -1);
    }
}

int main(){
    int n;
    cin >> n;
    string lrs;
    cin >> lrs;
    perm.push_back(1);
    for (auto it = lrs.begin(); it != lrs.end(); ++it) {
        action(*it, it-lrs.begin()+2);
    }
    for (auto it = perm.begin(); it != perm.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
