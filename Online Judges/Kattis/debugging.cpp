/*
 * https://open.kattis.com/problems/debugging
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define MAX_n 1000003

LL dp[MAX_n];
LL n, r, p;
LL cdp(LL i){
  if(dp[i] != -1)
      return dp[i];
  LL ans = LLONG_MAX;
  for (int j = 2; j <= i; ++j) {
      ans = min(ans, (j-1)*p + r + cdp(i/j + ((i%j)?1:0)));
  }
  return dp[i] = ans;
}

int main()
{
    cin>>n>>r>>p;
    fill_n(dp, n+1, -1);
    dp[1] = 0;
    cout<<cdp(n)<<endl;
    return 0;
}

