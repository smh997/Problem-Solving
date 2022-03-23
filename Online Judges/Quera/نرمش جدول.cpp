/*
 * https://quera.org/problemset/3413/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char arr[103][103], arr2[103][103];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j< n; ++j) {
            cin >> arr[i][j];
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;
        if(s == "H"){
            for (int i = 0; i < n / 2; ++i) {
                for (int j = 0; j < n; ++j) {
                    swap(arr[i][j], arr[n - i - 1][j]);
                }
            }
        }
        else if(s == "V"){
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n / 2; ++j) {
                    swap(arr[i][j], arr[i][n - j - 1]);
                }
            }
        }
        else{
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    arr2[j][n - 1 - i] = arr[i][j];
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    arr[i][j] = arr2[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j];
        }
        cout << endl;
    }

}
