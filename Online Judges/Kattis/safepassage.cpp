/*
 * https://open.kattis.com/problems/safepassage
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
int a[18];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n == 2){
        cout << max(a[0], a[1]) << endl;
        return 0;
    }
    sort(a, a + n);
    int ans = a[1];
    while(n > 2){
        if(n == 3)
            ans += a[0] + a[n - 1];
        else{
            if(2 * a[1] < a[0] + a[n - 2])
                ans += a[0] + a[n - 1] + 2 * a[1];
            else
                ans += a[0] + a[n - 1] + a[0] + a[n - 2];
        }
        n -= 2;
    }

    cout << ans << endl;
}