/*
 * https://open.kattis.com/problems/shuffling
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int arr[1003], targ[1003], tmp[1003];

bool same(){
    for (int i = 0; i < n; ++i) {
        if(arr[i] != targ[i]){
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> s;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        arr[i] = targ[i] = tmp[i] = i;
    }
    if(s == "in"){
        if(n%2){
            while(true){
                res++;
                int cnt = 1;
                for (int i = 1; i < n; i+=2) {
                    tmp[i] = arr[i-cnt];
                    cnt++;
                }
                cnt = 1;
                for (int i = n-3; i >= 0; i-=2) {
                    tmp[i] = arr[i+cnt];
                    cnt++;
                }
                for (int i = 0; i < n; ++i) {
                    arr[i] = tmp[i];
                }
                if(same())
                    break;
            }
        }
        else{
            while(true){
                res++;
                int cnt = 1;
                for (int i = 1; i < n; i+=2) {
                    tmp[i] = arr[i-cnt];
                    cnt++;
                }
                cnt = 1;
                for (int i = n-2; i >= 0; i-=2) {
                    tmp[i] = arr[i+cnt];
                    cnt++;
                }
                for (int i = 0; i < n; ++i) {
                    arr[i] = tmp[i];
                }
                if(same())
                    break;
            }
        }
    }
    else{
        if(n%2){
            while(true){
                res++;
                int cnt = 1;
                for (int i = 2; i < n; i+=2) {
                    tmp[i] = arr[i-cnt];
                    cnt++;
                }
                cnt = 1;
                for (int i = n-2; i > 0; i-=2) {
                    tmp[i] = arr[i+cnt];
                    cnt++;
                }
                for (int i = 0; i < n; ++i) {
                    arr[i] = tmp[i];
                }
                if(same())
                    break;
            }
        }
        else{
            while(true){
                res++;
                int cnt = 1;
                for (int i = 2; i < n; i+=2) {
                    tmp[i] = arr[i-cnt];
                    cnt++;
                }
                cnt = 1;
                for (int i = n-3; i > 0; i-=2) {
                    tmp[i] = arr[i+cnt];
                    cnt++;
                }
                for (int i = 0; i < n; ++i) {
                    arr[i] = tmp[i];
                }
                if(same())
                    break;
            }
        }
    }
    cout << res << endl;
    return 0;
}

