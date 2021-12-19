/*
 * https://open.kattis.com/problems/justforsidekicks
 * Author: https://github.com/smh997/
 */

#include<bits/stdc++.h>
using namespace std;

class FenwickTree { // Notice: it is 1-based fenwick-tree.
    public:
    vector<long long int> ft;
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

long long int n, q, a, b, c, res;
long long int value[10];
int arr[200003];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    scanf("%lld%lld\n", &n, &q);
    FenwickTree fenw[7];
    for (int i = 0; i < 6; ++i) {
        scanf("%lld", &a);
        value[i+1] = a;
        fenw[i+1].ft.assign(n + 1, 0); // init n + 1 zeroes
    }
    char ch[n];
    scanf("%s\n", ch);
    for (int i = 0; i < n; ++i) {
        arr[i+1] = ch[i] - '0';
        fenw[arr[i+1]].adjust(i+1, 1);
    }
    for (int i = 0; i < q; ++i) {
        scanf("%lld %lld %lld\n", &a, &b, &c);
        if(a == 1){
            fenw[arr[b]].adjust(b, -1);
            fenw[c].adjust(b, 1);
            arr[b] = c;
        }
        else if(a == 2){
            value[b] = c;
        }
        else{
            res = 0;
            for (int i = 0; i < 6; ++i) {
                res += fenw[i+1].rsq(b, c) * value[i+1];
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}
