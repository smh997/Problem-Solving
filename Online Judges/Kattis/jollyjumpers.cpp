/*
 * https://open.kattis.com/problems/jollyjumpers
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int a, b, n;
bool jollycheck[3003];

int main()
{
    while (cin >> n) {
        cin >> a;
        if (n == 1) {
            cout << "Jolly" << endl;
            continue;
        }
        fill_n(jollycheck, n, false);
        for (int i = 1; i < n; ++i) {
            cin >> b;
            jollycheck[abs(a-b)] = true;
            a = b;
        }
        bool flag = true;
        for (int i = 1; i < n; ++i)
            if (!jollycheck[i]){
                flag = false;
                break;
            }
        if (flag)
            cout << "Jolly" << endl;
        else 
            cout << "Not jolly" << endl;
    }
    return 0;
}

