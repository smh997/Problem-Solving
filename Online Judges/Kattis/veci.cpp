/*
 * https://open.kattis.com/problems/veci
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

string x;
int main()
{
    cin>>x;
    int leng = x.length();
    int arr[leng];
    for (int i = 0; i < leng; ++i) {
        arr[i] = x[i] - '0';
    }
    int a;int b = stoi(x);int res = INT_MAX;
    do{
        a = 0;
        for (int i = 0; i < leng; ++i) {
            a += pow(10, i) * arr[leng-i-1];
        }
        if(a>b && a<res)
            res = a;
    }while(next_permutation(arr, arr+leng));
    cout<<((res==INT_MAX)?0:res)<<endl;
    return 0;
}

