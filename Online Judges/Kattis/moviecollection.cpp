/*
 * https://open.kattis.com/problems/moviecollection
 * Author: https://github.com/smh997/
 */

#include<bits/stdc++.h>
using namespace std;

class FenwickTree { // Notice: it is 1-based fenwick-tree.
    public:
    vector<long long int> ft;
    FenwickTree(int n){
        ft.assign(n + 1, 0); // init n + 1 zeroes
    }
    long long int rsq(long long int b) { // returns RSQ(1, b)
        long long int summ = 0;
        for (; b; b -= (b & (-b)))
            summ += ft[b];
        return summ; 
    }
    long long int rsq(int a, int b) { // returns RSQ(a, b)
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(long long int k, long long int v) { // note: n = ft.size() - 1
        for (; k < ft.size(); k += (k & (-k)))
            ft[k] += v;
    }
};

int n, m , r, a;
int mp[200003];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    scanf("%d\n", &n);
    while(n--){
        scanf("%d %d\n", &m, &r);
        fill_n(mp, m+r, 0);
        FenwickTree fenw(r+m);
        for (int i = r+1; i <= r + m; ++i) {
            fenw.adjust(i, 1);
            mp[i-r] = i;
        }
        for (int i = 0; i < r; ++i) {
            scanf("%d", &a);
            printf("%lld ", fenw.rsq(mp[a]-1));
            fenw.adjust(mp[a], -1);
            mp[a] = r - i;
            fenw.adjust(mp[a], 1);
        }
        printf("\n");
    }
    return 0;
}
