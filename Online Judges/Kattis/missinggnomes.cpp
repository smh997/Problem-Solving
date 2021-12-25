/*
 * https://open.kattis.com/problems/missinggnomes
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

bool arr[100003];
int inp[100003];
set<int> ord;
int n, k;
int main()
{
    cin>>n>>k;
    for (int i = 1; i <= k; ++i) {
        cin>>inp[i];
        arr[inp[i]] = true;
    }
    int i=1, a = 1; 
    while(n){
        if(i>k || inp[i]>a){
            if(!arr[a]){
                cout<<a<<endl;
                n--;
            }
            a++;
        }
        else{
            cout<<inp[i]<<endl;
            if(inp[i]==a)
                a++;
            i++;
            n--;
        }
    }
    return 0;
}

