/*
 * https://open.kattis.com/problems/eko
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int n, m;
long long int arr[1000003];

bool judge(int h){
    long long int s = 0;
    for (int i = 0; i < n; ++i)
        if(arr[i]>h)
            s += arr[i]-h;
    return s >= m;
}

int main()
{
    cin>>n>>m;
    long long int lo=0, hi = 0, mid, res, ans = 0;
    for (int i = 0; i < n; ++i)
        cin>>arr[i], hi = max(arr[i], hi);
    sort(arr, arr+n);
    while(lo<hi){
        mid = (lo+hi)/2;
        res = judge(mid);
        if(res)lo = mid+1, ans=max(ans, mid);
        else hi = mid;
    }
    cout<<ans<<endl;
    return 0;
}

