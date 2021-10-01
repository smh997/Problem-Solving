/*
 * https://open.kattis.com/problems/divisible
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

long long int c, d, n, a, res;
long long int arr[50003];
map<int ,int> mp;
int main()
{
    cin >> c;
    while(c--){
        mp.clear();
        cin >> d >> n;
        cin >> a;
        arr[0] = a % d;
        for (int i = 1; i < n; ++i) {
            cin >> a;
            arr[i] = ((a % d) + (arr[i-1] % d)) % d;
        }
        for (int i = 0; i < n; ++i)
            mp[arr[i]]++;
        res = 0; mp[0]++;
        for (auto vv: mp)
            res += ((vv.second-1)*vv.second)/2;
        cout << res << endl;
    }
    return 0;
}

