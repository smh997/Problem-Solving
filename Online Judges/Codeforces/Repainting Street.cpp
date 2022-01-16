/*
 * https://codeforces.com/contest/1457/problem/B
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int arr[100003];
int t, n, k, mi, it, cnt;
set<int> color;
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        color.clear();
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            color.insert(arr[i]);
        }
        mi = n;
        for (auto c : color) {
            it = 0;
            cnt = 0;
            while(it<n){
                if(arr[it] != c){
                    cnt++;
                    it += k;
                }
                else{
                    it++;
                }
            }
            mi = min(cnt, mi);
        }
        cout << mi << endl;
    }
    return 0;
}
 