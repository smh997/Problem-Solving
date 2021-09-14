/*
 * https://open.kattis.com/problems/alphabet
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define forever while(1)
#define for(d1, d2, d3) for(d1; d2; d3)
#define loop(s, e) for(auto index = s, index != e, index++)
#define loop_reversely(s, e) for(auto index = s, index != e, index--)
#define save(n) auto n = index;
#define item (*index)
#define repeat(n) loop(0, n) // [0..n-1]
#define repeat_reversely(n) loop_reversely(n, 0) // [n..1]
#define iterate(d) loop(d.begin(), d.end())
#define iterate_reversely(d) loop(d.rbegin(), d.rend())

#define num unsigned long long int
#define inf LONG_LONG_MAX
using pn = pair<num, num>;

typedef vector<num> vn;
typedef vector<pn> vnn;
typedef vector<pair<num, pn>> vnnn;

#define pair(x, y) make_pair(x, y)
#define triple(x, y, z) make_pair(x, make_pair(y, z))
#define secondd second.first
#define third second.second

#define is_odd(x) (x&1)
#define is_even(x) (!odd(x))
#define div2(x) (x>>1)
#define mul2(x) (x<<1)
#define xswap(x, y) {x ^= y; y ^= x; x ^= y;} 

#define random(x, y) ((rand() % (y - x + 1)) + x)

#define start int main(int argv, char** argc){
#define finish return 0;}

int edit_distance(string x, string y, int replace_cost, int insert_cost, int delete_cost){
    num dp[x.size()+3][y.size()+3];
    loop_reversely(x.size(), -1){
        save(i)
        loop_reversely(y.size(), -1){
            save(j)
            if(i == x.size() && j == y.size()){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = inf;
                if(i < x.size() && j < y.size())
                    dp[i][j] = min(dp[i][j], (x[i] == y[j] ? 0 : replace_cost) + dp[i+1][j+1]);
                if(i < x.size())
                    dp[i][j] = min(dp[i][j], delete_cost + dp[i+1][j]);
                if(j < y.size())
                    dp[i][j] = min(dp[i][j], insert_cost + dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}

int main(){
    string y;
    cin >> y; 
    cout << edit_distance(y, "abcdefghijklmnopqrstuvwxyz", 1000000000, 1, 0) << endl;

}




