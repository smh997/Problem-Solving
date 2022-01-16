/*
 * https://codeforces.com/contest/1454/problem/C
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
int t, n;
int a[200003], aa;
bool vis[200003];
int mina;
int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        fill_n(vis, n+1, false);
        mina = INT_MAX;
        cin >> a[0];
        mp.clear();
        mp[a[0]] = 1;
        int j = 1;
        for (int i = 1; i < n; ++i) {
            cin >> aa;
            if(aa == a[j-1])
                continue;
            a[j++] = aa;
            mp[aa]++;
        }
        if(j==1){
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < j; ++i) {
            if(vis[a[i]])
                continue;
            if(a[i] == a[0] && a[i] == a[j-1]){
                mina = min(mp[a[i]] - 2 + 1, mina);
            }
            else if(a[i] == a[0] || a[i] == a[j-1]){
                mina = min(mina, mp[a[i]]);
            }
            else{
                mina = min(mina, mp[a[i]]+1);
            }
            vis[a[i]] = true;
        }
        cout << mina << endl;
    }
    return 0;
}
 