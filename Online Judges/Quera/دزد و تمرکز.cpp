/*
 * https://quera.org/problemset/2796/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000003];
int cc;

int main()
{
    cin>>n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i], arr[i] -= i + 1;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += arr[i];
        if(!s)
            cc++;
    }
    cout << cc << endl;
    return 0;
}

