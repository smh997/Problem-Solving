
/*
 * https://open.kattis.com/problems/zigzag2
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000003

int n;
int a[MAX_N];

int dp[MAX_N];
int dp2[MAX_N];
int p[MAX_N];
int p2[MAX_N];

// 1 2 3 4 2
// dp[0] = 1, p[0] = 1, dp2[0] = 1, p2[0] = 1
// dp[1] = 1, p[1] = 1, dp2[1] = 2, p2[1] = 2
// dp[2] = 1, p[2] = 1, dp2[2] = 2, p2[2] = 2
// dp[3] = 1, p[3] = 1, dp2[3] = 2, p2[3] = 2
// dp[4] = 3, p[4] = 2, dp2[4] = 2, p2[4] = 4

void compute(int x){
    dp[x] = dp[x-1];
    p[x] = p[x-1];
    if(p2[x-1] > a[x] && dp2[x-1] + 1 >= dp[x]){
        dp[x] = dp2[x-1] + 1;
        p[x] = a[x];
    }
    dp2[x] = dp2[x-1];
    p2[x] = p2[x-1];
    if(p[x-1] < a[x] && dp[x-1] + 1 >= dp2[x]){
        dp2[x] = dp[x-1] + 1;
        p2[x] = a[x];
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    dp[0] = 1;
    dp2[0] = 1;
    p[0] = a[0];
    p2[0] = a[0];
    for (int i = 1; i < n; ++i) {
        compute(i);
    }

    printf("%d\n", max(dp[n-1], dp2[n-1]));
}