/*
 * https://open.kattis.com/problems/runningsteps
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

long long int comb[53][53];
int t, k, n;
void genComb(){
    comb[0][0] = 1;
    for (int i = 1; i <= 50; i++)
        for (int j = 0; j <= i; j++)
            comb[i][j] = (i-1 >= 0 && j-1 >= 0 ? comb[i-1][j-1] : 0) + (i-1 >= 0 && j <= i ? comb[i-1][j] : 0);
}
long long step(int n) {
  long long ans = 0;
  int ones=0, twos;
  while(true){
      twos = (n - 2*ones)/4;
      if(ones>twos)
          break;
      if(2*ones + 4*twos == n)
          ans += comb[ones+twos][ones] * comb[ones+twos][ones];
      ones++;
  }
  return ans;

}

int main()
{
    genComb();
    cin>>t;
    while (t--) {
        cin>>k>>n;
        cout<<k<<" "<<step(n)<<endl;
    }
    
    return 0;
}

