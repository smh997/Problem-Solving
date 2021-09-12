/*
 * https://open.kattis.com/problems/aboveaverage
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int c;
    cin>>c;
    while(c--){
        int n;
        cin>>n;
        int arr[n],sum=0,count=0;
        double avg;
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
            sum+=arr[i];
        }
        avg = (double)sum/n;
        for (int i = 0; i < n; ++i) {
            if(arr[i]>avg)count++;
        }
        printf("%.3f%%\n",(float)count/n *100);

    }
    return 0;
}

