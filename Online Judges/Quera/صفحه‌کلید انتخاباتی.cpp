/*
 * https://quera.org/problemset/7998/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    bool caps = false;
    cin >> n;
    string input;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        if (input == "CAPS")
            caps = !caps;
        else 
            cout << (char)(caps == true ? input[0] - 32 : input[0]);
    }
    cout << endl;
    return 0;
}

