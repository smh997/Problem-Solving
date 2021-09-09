#include <bits/stdc++.h>
using namespace std;

// Catalan Numbers using DP VS Formula

long long int dp[23], cat[23];

int main(){
    dp[0] = 1;
    for(int n = 1; n <= 20; n++)
        for(int k = 0; k < n; k++)
            dp[n] += dp[k] * dp[n - 1 - k];
    cat[0] = 1;
    for(int n = 1; n <= 20; n++)
        cat[n] = (cat[n - 1] * (4 * n - 2)) / (n + 1);
    for(int n = 0; n <= 20; n++)
        cout << n << " " << dp[n] << " " << cat[n] << endl; 
}