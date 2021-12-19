/*
 * https://open.kattis.com/problems/guess
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int low=1, high=1000, mid;
    
    while(true){
        mid = (low+high)>>1;
        cout<<mid<<endl;
        cin>>s;
        if(s=="correct")
            break;
        if(s=="lower")
            high = mid-1;
        else
            low = mid+1;
        cout.flush();
    }
    return 0;
}

