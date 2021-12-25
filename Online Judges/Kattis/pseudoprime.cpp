/*
 * https://open.kattis.com/problems/pseudoprime
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

long long int powmod(long long int x, long long int y, long long int p)  
{  
    long long int res = 1;
    x = x % p; // Update x if it is more than or equal to p 
    if (x == 0) 
        return 0; // In case x is divisible by p;   
    while (y > 0)  
    {  
        if (y & 1)// if y is odd
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;  
} 

int main()
{
    sieve(10000000);
    int a, p;
    while(cin >> p >> a && p && a){
        if(!isPrime(p) && powmod(a, p, p) == a % p){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
    return 0;
}

