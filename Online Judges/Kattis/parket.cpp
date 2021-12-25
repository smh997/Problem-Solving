/*
 * https://open.kattis.com/problems/parket
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int r, b;

int main()
{
    cin >> r >> b;
    int ans1 = 2, ans2;
    int a = r+b;
    while(true){
        if(!(a % ans1)){
            ans2 = a / ans1;
            if(2*(ans1 + ans2) == r + 4){
                cout << ans2 << " " << ans1 << endl;
                break;
            }
        }
        ans1++;
    }
    return 0;
}

