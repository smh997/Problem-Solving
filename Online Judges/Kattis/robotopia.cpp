/*
 * https://open.kattis.com/problems/robotopia
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int t, l1, a1, l2, a2, lt, at;

int main(){
    cin >> t;
    while(t--){
        cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;
        int ans = 0, x, y;
        for(int n = 1; n <= 10000; n++){
            int e = lt - n * l1;
            if(e <= 0)
                continue;
            if(e % l2)
                continue;
            e /= l2;
            int f = at - n * a1;
            if(f <= 0)
                continue;
            if(f % a2)
                continue;
            f /= a2;
            if(e == f)
                ans++, x = n, y = e;
        }
        if(ans == 1)
            cout << x << " " << y << endl;
        else
            cout << "?" << endl;
    }
}