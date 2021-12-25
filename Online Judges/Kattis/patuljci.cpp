/*
 * https://open.kattis.com/problems/patuljci
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int arr[9];

int main()
{
    int s = 0, n = 9;
    for (int i = 0; i < n; ++i)
        cin>>arr[i], s+=arr[i];
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if(s-arr[i]-arr[j]==100){
                for (int k = 0; k < n; ++k)
                    if(k!=i && k!=j)
                        cout<<arr[k]<<endl;
                return 0;
            }
    return 0;
}

