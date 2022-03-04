/*
 * https://quera.org/problemset/82379/
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int c, n, p[33];

int main(){
    cin >> c >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    int i = 0, j;
    while(i + 1 < n){
        if(p[i + 1] <= p[i]){
            i++;
            continue;
        }
        j = i + 1;
        while(j + 1 < n && p[j + 1] > p[j])
            j++;
        int k = c / p[i];
        c -= k * p[i], c += k * p[j];
        i = j + 1;
    }
    cout << c << endl;
}