/*
 * https://open.kattis.com/problems/reseto
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010
long long int _sieve_size;
bitset<MAX_N> pFlags;
int n, k;
void sieve(long long int upperbound){
    _sieve_size = upperbound;
    pFlags.set();
    pFlags[0] = pFlags[1] = 0;
    k--;//cerr<<2<<endl;
    if(!k){
        cout<<2<<endl;
        return;
    }
    for(long long int q = 4; q <= _sieve_size; q += 2){
        pFlags[q] = 0;
        k--;//cerr<<q<<endl;
        if(!k){
            cout<<q<<endl;
            return;
        }            
    }    
    for(long long int p = 3; p <= _sieve_size; p += 2){ // constraint can be p * p <= _sieve_size if we don't need to calc PF
        if(pFlags[p]){
            k--;//cerr<<p<<endl;
            if(!k){
                cout<<p<<endl;
                return;
            }
            for(long long int q = p * p; q <= _sieve_size; q += p){
                if(pFlags[q]){
                    pFlags[q] = 0;
                    k--;//cerr<<q<<endl;
                    if(!k){
                        cout<<q<<endl;
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    sieve(n);    
    return 0;
}

