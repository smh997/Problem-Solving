/*
 * https://open.kattis.com/problems/freeweights
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, arr1[1000003], arr2[1000003];
vector<int> v1, v2;

bool judge(int x){
    v1.clear();
    v2.clear();
    for (int i = 0; i < n; ++i) {
        if(arr1[i]<=x) continue;
        v1.push_back(arr1[i]);
    }
    if(v1.size()%2) return false;
    for (int i = 0; i < v1.size(); i+=2)
        if(v1[i]!=v1[i+1]) return false;
    for (int i = 0; i < n; ++i) {
        if(arr2[i]<=x) continue;
        v2.push_back(arr2[i]);
    }
    if(v2.size()%2) return false;
    for (int i = 0; i < v2.size(); i+=2)
        if(v2[i]!=v2[i+1]) return false;
    return true;
}

int main()
{
    cin>>n;
    int lo=0, hi=0, mid;
    for (int i = 0; i < n; ++i)
        cin>>arr1[i], hi = max(hi, arr1[i]);
    for (int i = 0; i < n; ++i)
        cin>>arr2[i], hi = max(hi, arr2[i]);
    while(lo<hi){
        mid = (lo+hi)/2;//cout<<mid<<endl;
        if(judge(mid))
            hi = mid;
        else
            lo = mid+1;
    }
    cout<<lo<<endl;
    return 0;
}

