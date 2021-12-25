/*
 * https://open.kattis.com/problems/outofsorts
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 3;

#define num long long int

int n;
num m, a, c, x0, seq[maxn];

int main(){
    cin >> n >> m >> a >> c >> x0;
    seq[0] = (a * x0 + c) % m;
    for(int i = 1; i < n; i++)
        seq[i] = (a * seq[i-1] + c) % m;    
    int ans = 0;
    for(int i = 0; i < n; i++){
        int lo = 0, hi = n-1;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(seq[mid] == seq[i]){
                    lo = mid;
                    break;
            }
            else if(seq[mid] > seq[i])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        if(seq[lo] == seq[i])
            ans++;
    }
    cout << ans << endl;
}