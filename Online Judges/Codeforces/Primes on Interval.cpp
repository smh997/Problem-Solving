/*
 * https://codeforces.com/contest/237/problem/C
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000010
long long int _sieve_size;
bitset<MAX_N> pFlags;

int primecount[1000003];
void sieve(long long int upperbound){
    _sieve_size = upperbound + 1;
    pFlags.set();
    pFlags[0] = pFlags[1] = 0;
    for(long long int q = 4; q <= _sieve_size; q += 2){
        pFlags[q] = 0;
    }
    for(long long int p = 3; p <= _sieve_size; p += 2){ // constraint can be p * p <= _sieve_size if we don't need to calc PF
        if(pFlags[p]){
            for(long long int q = p * p; q <= _sieve_size; q += p){
                if(pFlags[q]){
                    pFlags[q] = 0;
                }
            }
        }
    }
}
int a, b, k;

bool judge(int c){
    for (int i = a; i <= b-c+1; ++i) {
        if(primecount[i+c-1]-primecount[i-1] < k){
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> a >> b >> k;
    sieve(2000000);
    for (int i = 1; i < b+10; ++i)
        primecount[i] = primecount[i-1] + ((pFlags[i])?1:0);
    int lo = 1, hi = b-a+1, mid;
    while(lo < hi){
        mid = (lo+hi)/2;
        if(judge(mid)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    if(judge(lo))
        cout << lo << endl;
    else
        cout << -1 << endl;
    return 0;
}
 