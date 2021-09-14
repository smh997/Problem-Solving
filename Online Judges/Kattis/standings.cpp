/*
 * https://open.kattis.com/problems/standings
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int t, n;string name;
long long int arr[100003];
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for (int i = 1; i <= n; ++i) {
            cin>>name>>arr[i];
        }
        sort(arr+1, arr+n+1);
        long long int res = 0;
        for (int i = 1; i <= n; ++i) {
            res += abs(arr[i]-i);
        }
        cout<<res<<endl;
    }
    return 0;
}

