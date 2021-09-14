/*
 * https://open.kattis.com/problems/abc
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr;
    int a;
    for (int i = 0; i < 3; ++i) {
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    string s;
    cin>>s;
    for (int i = 0; i < 3; ++i) {
        if(s[i]=='A')cout<<arr[0]<<" ";
        else if(s[i]=='B')cout<<arr[1]<<" ";
        else cout<<arr[2]<<" ";
    }
    cout<<endl;
    return 0;
}

