/*
 * https://codeforces.com/contest/1324/problem/D
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin>>n;
    long long int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>a;
        arr[i] -= a;
    }
    sort(arr, arr+n);
    long long int res = 0, i;
    for (i = 0; i < n; ++i) {
        if(arr[i] > 0)
            break;
        auto it = lower_bound(arr,arr+n,(-arr[i])+1);
        if(it!=arr+n){
            res += n-(it-arr);
//            cout<<arr[i]<<" "<<*it<<" "<<n-(it-arr)<<endl;
        }
    }
    res += ((long long int)(n - i)*(n-i-1))/2;
    cout<<res<<endl;
    return 0;
}
 