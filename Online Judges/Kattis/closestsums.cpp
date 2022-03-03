/*
 * https://open.kattis.com/problems/closestsums
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;
const int siz = 1000 * 1001 / 2 + 5;
int n, m, inp[1003], arr[siz], c = 1, q, it;

int main()
{
    while(cin >> n){
        it = 0;
        for (int i = 0; i < n; ++i)
            cin >> inp[i];
        for (int i = 0; i < n-1; ++i)
            for (int j = i+1; j < n; ++j)
                arr[it++] = inp[i] + inp[j];
        sort(arr, arr + it);
        cin >> m;
        cout << "Case "<< c << ":" << endl;
        for (int i = 0; i < m; ++i) {
            cin >> q;
            int pos = upper_bound(arr, arr + it, q) - arr;
            cout << "Closest sum to "<< q <<" is ";
            if (pos == it){
                cout << arr[pos-1] << "." << endl;
            }
            else if (pos == 0){
                cout << arr[pos] << "." << endl;
            }
            else if (abs(arr[pos]-q) < abs(arr[pos-1]-q)){
                cout << arr[pos] << "." << endl;
            }
            else{
                cout << arr[pos-1] << "." << endl;
            }
        }
        c++;
    }
    return 0;
}

