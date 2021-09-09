#include <bits/stdc++.h>
using namespace std;

// Segment Tree Implementation

// Example: Bitmask of Distinct Characters on Intervals of a String

const int maxn = 1e5;

string s;
int t[4 * maxn + 3];

// O(n * log(n))
void build(int v, int tl, int tr){
    if(tl == tr)
        t[v] |= (1 << (s[tl] - 'a')); // Base Case
    else{
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] | t[2 * v + 1]; // Combine
    }
}

// O(log(n))
void update(int v, int tl, int tr, int pos, char c){
    if(tl == tr)
        t[v] = (1 << (c - 'a')); // Base Case
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(2 * v, tl, tm, pos, c);
        else
            update(2 * v + 1, tm + 1, tr, pos, c);
        t[v] = t[2 * v] | t[2 * v + 1]; // Combine
    }
}

// O(log(n))
int query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0; // Nill
    if(l == tl && r == tr)
        return t[v]; // Hit
    int tm = (tl + tr) / 2;
    int mask1 = query(2 * v, tl, tm, l, min(tm, r));
    int mask2 =  query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    return mask1 | mask2; // Combine
}

int main(){
    cin >> s;
	int n = s.size();
    build(1, 0, n - 1);
	// handle queries and updates, initially put v = 1, tl = 0, tr = n - 1
}