/*
 * https://open.kattis.com/problems/spacerace
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double d, f, v;
    string racer;
    cin >> n;
    cin >> d;
    double min_fuel = 1e9;
    string winner;
    for (int i = 0; i < n; i++) {
        cin >> racer >> v >> f;
        if (f < min_fuel) {
            min_fuel = f;
            winner = racer;
        }
    }
    cout << winner << endl;
}
