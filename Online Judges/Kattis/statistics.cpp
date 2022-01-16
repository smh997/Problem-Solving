/*
 * https://open.kattis.com/problems/statistics
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, mi=INT_MAX, mx=INT_MIN, c=1;
    while(cin>>n){
        mi=INT_MAX;mx=INT_MIN;
        for(int i=0; i<n; i++){
            cin>>a;
            mi = min(mi, a);
            mx = max(mx, a);
        }
        cout<<"Case "<< c <<": "<<mi<<" "<<mx<<" "<<mx-mi<<endl;
        c++;
    }
    return 0;
}