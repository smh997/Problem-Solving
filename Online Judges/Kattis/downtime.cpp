/*
 * https://open.kattis.com/problems/downtime
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    int start = 0, timeout=1, m=1;
    for (int i = 1; i < n; ++i) {
        while(arr[start] + 1000 <= arr[i]){
            start++;
            timeout--;
        }
        timeout++;
        m = max(m,timeout);
    }
    cout<<ceil((float)m/k)<<endl;
    return 0;
}

