/*
 * https://open.kattis.com/problems/communication
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;
        for(int k = 0; k < 256; k++){
            int z = k ^ (k << 1);
            if(z & (1 << 8))
                z -= (1 << 8);
            if(z == x){
                cout << k << " ";
                break;
            }
        }
    }
}