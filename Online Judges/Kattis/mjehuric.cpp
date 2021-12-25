/*
 * https://open.kattis.com/problems/mjehuric
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int arr[5], tmp;

bool satisfied(){
    for (int i = 0; i < 5; ++i) {
        if(arr[i]!=i+1)
            return false;
    }
    return true;
}

void show(){
    for (int i = 0; i < 5; ++i) {
        cout<<arr[i]<<((i==4)?"\n":" ");
    }
}

int main()
{
    for (int i = 0; i < 5; ++i)
        cin>>arr[i];
    while(!satisfied()){
        for (int i = 0; i < 4; ++i) {
            if(arr[i]>arr[i+1]){
               tmp = arr[i];
               arr[i] = arr[i+1];
               arr[i+1] = tmp;
               show();
            }
        }
    }
    
    return 0;
}

