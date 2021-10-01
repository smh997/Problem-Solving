/*
 * https://open.kattis.com/problems/fenwick
 * Author: https://github.com/smh997/
 */

#include<bits/stdc++.h>
using namespace std;

class FenwickTree {
    private: 
    vector<long long int> ft; // recall that vi is: typedef vector<int> vi;
    public:
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

long long int n, q, a, b;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
    scanf("%lld%lld\n", &n, &q);
    char ch;
//    vector<long long int> res;
    FenwickTree fenw(n);
    for (int i = 0; i < q; ++i) {
        scanf("%c", &ch);
        if(ch == '+'){
            scanf("%lld%lld\n", &a, &b);
            fenw.adjust(a+1, b);
        }
        else{
            scanf("%lld\n", &a);
//            res.push_back(fenw.rsq(a));
            printf("%lld\n", fenw.rsq(a));
        }
    }
//    for (int i = 0; i < res.size(); ++i) {
//        cout << res[i] << endl;
//    }
    return 0;
}
