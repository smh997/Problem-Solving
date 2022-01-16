/*
 * https://open.kattis.com/problems/magical3
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

vector<long long int> factors;
void primeFactors(long long int N) {
    long long int PF_idx = 0, primefactor = PF[PF_idx];
    while (primefactor * primefactor <= N) { // stop at sqrt(N); N can get smaller
        while (N % primefactor == 0){
            N /= primefactor; // remove PF
            factors.push_back(primefactor);
        } 
        primefactor = PF[++PF_idx]; // only consider primes
    }
    if (N != 1)
        factors.push_back(N); // special case if N is a prime
}

int main()
{
    int n;
    int candidate;
    sieve(10000000);
    while(cin >> n && n){
        if(n == 3){
            cout << 4 << endl;
            continue;
        }
        else if(n < 7){
            cout << "No such base" << endl;
            continue;
        }
        candidate = n-3;
        factors.clear();
        primeFactors(candidate);
        long long int ans = INT_MAX;
        for (int i = 0; i < factors.size(); ++i) {
            if(factors[i]>3){
                ans = factors[i];
                break;
            }
        }
        if(factors.size() > 1){
            ans = min(ans, factors[0] * factors[1]);
        }
        cout << ans << endl;
    }
    
    return 0;
}

