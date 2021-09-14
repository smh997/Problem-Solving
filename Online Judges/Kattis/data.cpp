/*
 * https://open.kattis.com/problems/data
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010

int numDiffPF[MAX_N];
void modified_sieve(){ // calculate number of diffferent PFs
    for (int i = 2; i < MAX_N; i++)
        if (numDiffPF[i] == 0) // i is a prime number
            for (int j = i; j < MAX_N; j += i)
                numDiffPF[j]++; // increase the values of multiples of i
}
int n;
int s[15];
int dp[(1<<14)+3];
int main()
{
    modified_sieve();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 1; i < (1<<n); ++i) {
        int sum = 0;
        for (int b = 0; b < n; ++b) {            
            if(i & (1<<b)){
                sum += s[b];
            }
        }
//        cerr << "sum: " << sum << " " << i << endl; 
//        int d = 2;
//        while(sum > 1){
//            if(!(sum % d))
//                dp[i]++;
//            while(!(sum % d))
//                sum /= d;
//            d++;
//        }
//        cerr << "dp: " << dp[i] << " " << i << endl;
        dp[i] = numDiffPF[sum];
    }
    for (int mask = 1; mask < (1<<n); ++mask) {
        int prevy = mask & (mask-1);
        while(prevy != 0){
            dp[mask] = max(dp[mask], dp[mask-prevy] + dp[prevy]);
            prevy = mask & (prevy-1);
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}
