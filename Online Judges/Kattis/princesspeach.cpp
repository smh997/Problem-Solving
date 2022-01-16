/*
 * https://open.kattis.com/problems/princesspeach
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

bool seen[103];
int n, k, a;
int main()
{
    cin>>n>>k;
    for (int i = 0; i < k; ++i) {
        cin>>a;
        seen[a]=true;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if(seen[i])res++;
        else cout<<i<<endl;
    }
    cout<<"Mario got "<<res<<" of the dangerous obstacles."<<endl;
    return 0;
}

