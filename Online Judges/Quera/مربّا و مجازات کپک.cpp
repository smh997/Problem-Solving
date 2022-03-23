/*
 * https://quera.org/problemset/20252/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int main(){    
    int n;
    cin >> n;
    int a[100003];
    int b[100003];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    bool yes = true;
    for(int i = 0; i < n; i++)
        if(b[i] > a[i])
            yes = false;
    cout << (yes ? "YES" : "NO") << endl;
}