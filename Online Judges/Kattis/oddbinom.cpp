/*
 * https://open.kattis.com/problems/oddbinom
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

long long int rec(long long int n){
    if(n == 1 || n == 0){
        return n;
    }
    if(n%2)
        return 2 * rec(n/2) + rec(n/2 + 1);
    return 3 * rec(n/2);
}

int main()
{
    long long int n;
    cin >> n;
    cout << rec(n) << endl;
    return 0;
}

