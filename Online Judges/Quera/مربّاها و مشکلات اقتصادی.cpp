/*
 * https://quera.org/problemset/20249/
 * Author: https://github.com/smh997/
 */
#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        sum += a;
    }
    cout << ((n * k - sum) / k) << endl;
}