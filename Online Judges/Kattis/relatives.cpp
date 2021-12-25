/*
 * https://open.kattis.com/problems/relatives
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

long long int EulerPhi(long long int N) { // Count the number of positive integers < N that are relatively prime to N
    long long int PF_idx = 0, primefactor = PF[PF_idx], ans = N; // start from ans = N
    while (primefactor * primefactor <= N) {
        if (N % primefactor == 0)
            ans -= ans / primefactor; // only count unique factor
        while (N % primefactor == 0)
            N /= primefactor;
        primefactor = PF[++PF_idx];
    }
    if (N != 1)
        ans -= ans / N; // last factor
    return ans;
}

int main()
{
    sieve(10000000);
    int x;
    while(cin >> x && x){
        cout << EulerPhi(x) << endl;
    }
    return 0;
}

