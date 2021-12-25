/*
 * https://open.kattis.com/problems/pivot
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100003
int arr[MAX_N];
int LRmx[MAX_N];
int RLmi[MAX_N];
int n;
int main()
{
    cin>>n;
    int mx = INT_MIN, mi = INT_MAX, res =0;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        LRmx[i] = mx = max(mx, arr[i]);
    }
    for (int i = n-1; i >= 0; --i) {
        RLmi[i] = mi = min(mi, arr[i]);
        if(RLmi[i]==LRmx[i])
            res++;
    }
    cout<<res<<endl;
    return 0;
}
