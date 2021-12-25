/*
 * https://open.kattis.com/problems/pascal
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

int getSPF(long long int N) {
    if (N <= _sieve_size)
        return spf[N];
    for (int i = 0; i < (int)PF.size(); i++){
        if (N % PF[i] == 0)
            return PF[i];
    }
    return N; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in PF)^2

int main()
{
    sieve(10000000);
    int n;
    cin >> n;
    int smallpf = getSPF(n);
    if(n==1 || smallpf == n)
        cout << n - 1 << endl;
    else
        cout << n - (n/smallpf) << endl;
    return 0;
}

