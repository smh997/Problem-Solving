/*
 * https://quera.org/problemset/6402/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;

void f(string* arr, int i, int j, string s){
    cout << arr[i] << " to " << arr[j] << " : " << s << endl;
}

int main(){
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    string s1 = "ke ba in dar agar dar bande dar manand, dar manand.",
            s2 = "dar manand?", s3 = "dar manand.";
    for (int i = 0; i < n-1; i++){
        f(arr, i, i + 1, s1);
        for (int j = i + 1; j > 0; j--){
            f(arr, j, j - 1, s2);
        }
        for(int k = 0; k <= i; k++)
            f(arr, k, k + 1, s3);
    }
}