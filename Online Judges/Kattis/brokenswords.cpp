/*
 * https://open.kattis.com/problems/brokenswords
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define read(t, d) t d; cin >> d;

#define print(d) cout << (d);
#define prints(d) cout << (d) << " ";
#define printl(d) cout << (d) << endl;

#define debug(d) cerr << (d);
#define debugs(d) cerr << (d) << " ";
#define debugl(d) cerr << (d) << endl;

#define forever while(1)
#define for(d1, d2, d3) for(d1; d2; d3)
#define loop(s, e) for(auto index = s, index != e, index++)
#define save(n) auto n = index;
#define item (*index)
#define repeat(n) loop(0, n)
#define iterate(d) loop(d.begin(), d.end())
#define iterate_reversely(d) loop(d.rbegin(), d.rend())

#define num long long int
#define inf LONG_LONG_MAX
using pn = pair<num, num>;

typedef vector<num> vn;
typedef vector<pn> vnn;
typedef vector<pair<num, pn>> vnnn;

#define pair(x, y) make_pair(x, y)
#define triple(x, y, z) make_pair(x, make_pair(y, z))
#define secondd second.first
#define third second.second

#define odd(x) (x&1)
#define even(x) (!odd(x))
#define div2(x) (x>>1)
#define mul2(x) (x<<1)
#define xswap(x, y) {x ^= y; y ^= x; x ^= y;} 

#define random(x, y) ((rand() % (y - x + 1)) + x)

#define start int main(void){
#define finish return 0;}

start
    read(int, N)
    int L = 0, U = 0;
    repeat(N){
        char a[5];
        cin >> a;
        if(a[0] == '0')
            U += 1;
        if(a[1] == '0')
            U += 1;
        if(a[2] == '0')
            L += 1;
        if(a[3] == '0')
            L += 1;
    }
    int div = min(L, U) / 2;
    int rem1 = U - 2 * div;
    int rem2 = L - 2 * div;
    prints(div) prints(rem1) printl(rem2)  
finish
