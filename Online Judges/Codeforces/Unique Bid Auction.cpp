/*
 * https://codeforces.com/contest/1454/problem/B
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> s;
int t, n, id;
int vis[200003];
int a[200003];
int mina;
int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        fill_n(vis, n+1, false);
        id = -1;mina = INT_MAX;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            vis[a[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            if(vis[a[i]]==1){
                if(mina > a[i])
                    mina = a[i], id = i+1;
            }
        }
        cout << id << endl;
    }
    return 0;
}
 