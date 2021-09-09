#include <bits/stdc++.h>
using namespace std;

// Lazy Segment Tree Implementation

// Example: Query = Obtaining minimum of a range
// Example: Update = Adding a constant value to a range

const int maxn = 1e5;
const int inf = INT_MAX;

int n, arr[maxn + 3];
int seg[4 * maxn + 3], lazy[4 * maxn + 3];

// O(n * log(n))
void build(int v, int tl , int tr){
    if(tl == tr)
        seg[v] = arr[tl];
    else{
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid + 1, tr);
        seg[v] = min(seg[2 * v], seg[2 * v + 1]);
    }
}

// O(1)
void push(int v){
    seg[2 * v] += lazy[v];
    seg[2 * v + 1] += lazy[v];
    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
    lazy[v] = 0;
}

// O(log(n))
void update(int v, int tl, int tr, int l , int r, int val){
    if(l > r)
        return;
    if(l == tl && tr == r){
        seg[v] += val;
        lazy[v] += val;
        return;
    }
    push(v);
    int mid = (tr + tl) / 2;
    update(2 * v, tl, mid, l, min(r, mid), val);
    update(2 * v + 1, mid + 1, tr, max(l, mid + 1), r, val);
    seg[v] = min(seg[2 * v], seg[2 * v + 1]);
}

// O(log(n))
int query(int v, int tl, int tr, int l , int r){
    if(l > r)
        return inf;
    if(l == tl && tr == r)        
        return seg[v];
    push(v);
    int mid = (tr + tl) / 2;
    return min(query(2 * v, tl, mid, l, min(r, mid)), query(2 * v + 1, mid + 1, tr, max(l, mid + 1), r));    
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    // handle queries and updates, initially put v = 1, tl = 0, tr = n - 1
}