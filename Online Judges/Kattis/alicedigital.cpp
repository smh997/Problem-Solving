/*
 * https://open.kattis.com/problems/alicedigital
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int t, n, m, dpl[100003], dpr[100003], arr[100003];

int main()
{
    cin >> t;
    while(t--){
        cin >> n >> m;
        fill_n(dpl, n, 0);
        fill_n(dpr, n, 0);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        dpl[0] = (arr[0] > m) ? arr[0] : 0;
        dpr[n-1] = (arr[n-1] > m) ? arr[n-1] : 0;
        for (int i = 1; i < n; ++i)
            dpl[i] = (arr[i] > m) ? arr[i] + dpl[i-1] : 0;
        for (int i = n-2; i >= 0; --i)
            dpr[i] = (arr[i] > m) ? arr[i] + dpr[i+1] : 0;
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if(arr[i] == m)
                ans = max(ans, m + ((i > 0) ? dpl[i-1] : 0) + ((i < n-1) ? dpr[i+1] : 0));
        cout << ans << endl;
    }
    return 0;
}

