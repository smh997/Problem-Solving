/*
 * https://open.kattis.com/problems/palindromicpassword
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> all;

int main(){
    for(int d1 = 1; d1 <= 9; d1++)
        for(int d2 = 0; d2 <= 9; d2++)
            for(int d3 = 0; d3 <= 9; d3++){
                string c1 = to_string(d1), c2 = to_string(d2), c3 = to_string(d3);
                string num = c1 + c2 + c3 + c3 + c2 + c1;
                all.push_back(stoi(num));
            }
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int diff = INT_MAX, ans;
        for(int y : all)
            if(abs(y - x) < diff)
                diff = abs(y - x), ans = y;
        cout << ans << endl;
    }
}