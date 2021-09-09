#include<bits/stdc++.h>
using namespace std;

class FenwickTree { // Notice: it is 1-based fenwick-tree.
    private: 
    vector<long long int> ft;
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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    //  get input with fast io functions.
    //  it is better to save the result and output them at the end.
    
    return 0;
}