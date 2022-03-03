/*
 * https://open.kattis.com/problems/polymul1
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>

using namespace std;

int T, n, m, p1[259], p2[259], res[520];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i <= n; ++i)
            cin >> p1[i];
        cin >> m;
        for (int i = 0; i <= m; ++i)
            cin >> p2[i];
        fill_n(res, n + m + 1, 0);
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                res[i+j] += p1[i] * p2[j];
        cout << n + m << endl;
        for (int i = 0; i < n+m; ++i) {
            cout << res[i] << " ";
        }
        cout << res[n+m] << endl;
    }

    return 0;
}

