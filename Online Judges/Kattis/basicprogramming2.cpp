/*
 * https://open.kattis.com/problems/basicprogramming2
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, arr[200003], t;

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    if(t == 1){
        int lo = 0, hi = n-1;
        while(lo != hi){
            if(arr[lo] + arr[hi] == 7777){
                cout << "Yes" << endl;
                return 0;
            }
            if(arr[lo] + arr[hi] > 7777){
                hi--;
            }
            else{
                lo++;
            }
        }
        cout << "No" << endl;
    }
    else if(t == 2){
        for (int i = 1; i < n; ++i) {
            if(arr[i] == arr[i-1]){
                cout << "Contains duplicate" << endl;
                return 0;
            }
        }
        cout << "Unique" << endl;
    }
    else if(t == 3){
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if(arr[i] == arr[i-1]){
                cnt++;
                if(cnt > n/2){
                    cout << arr[i] << endl;
                    return 0;
                }
            }
            else{
                cnt = 1;
            }
        }
        cout << -1 << endl;
    }
    else if(t == 4){
        if(n%2){
            cout << arr[n/2] << endl;
        }
        else{
            cout << arr[n/2-1] << " " << arr[n/2] << endl;
        }
    }
    else{
        for (int i = 0; i < n; ++i) {
            if(arr[i] >= 100 && arr[i] <= 999){
                cout << arr[i] << " ";
            }
        }
    }
    return 0;
}

