/*
 * https://codeforces.com/contest/1454/problem/D
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000010
long long int _sieve_size;
bitset<MAX_N> pFlags;
long long int spf[MAX_N]; // smallest pf of numbers
vector<long long int> PF;

void sieve(long long int upperbound){
    _sieve_size = upperbound + 1;
    pFlags.set();
    pFlags[0] = pFlags[1] = 0;
    for(long long int q = 4; q <= _sieve_size; q += 2){
        pFlags[q] = 0;
        spf[q] = 2;
    }
    PF.push_back(2);
    for(long long int p = 3; p <= _sieve_size; p += 2){ // constraint can be p * p <= _sieve_size if we don't need to calc PF
        if(pFlags[p]){
            spf[p] = p;
            for(long long int q = p * p; q <= _sieve_size; q += p){
                if(pFlags[q]){
                    pFlags[q] = 0;
                    spf[q] = p;
                }
            }
            PF.push_back(p);
        }
    }
}

bool isPrime(long long int N) {
    if (N <= _sieve_size)
        return pFlags[N];
    for (int i = 0; i < (int)PF.size(); i++){
        if (N % PF[i] == 0)
            return false;
    }
    return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in PF)^2
long long int pri = 0, pri_i;
long long int sumDiv(long long int N) {
    long long int PF_idx = 0, primefactor = PF[PF_idx], ans = 1; // start from ans = 1
    while (primefactor * primefactor <= N) {
        long long int power = 0;
        while (N % primefactor == 0){
            N /= primefactor;
            power++;
        }
        if(pri < power){
            pri = power;
            pri_i = primefactor;
        }
        primefactor = PF[++PF_idx];
    }
    if (N != 1){
        if(pri < 1){
            pri = 1;
            pri_i = N;
        }
    }
    return pri_i;
}
long long int n, t;
int main()
{
    sieve(10000000);
    cin >> t;
    while(t--){
        cin >> n;
        pri = 0;
        if(sumDiv(n) == n){
            cout << 1 << endl;
            cout << n << endl;
            continue;
        }
        cout << pri << endl;
        for (int i = 0; i < pri-1; ++i) {
            cout << pri_i << " ";
            n /= pri_i;
        }
        cout << n << endl;
        
    }
    
    return 0;
}
 