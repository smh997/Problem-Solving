/*
 * https://open.kattis.com/problems/turbo
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100003

int n;
int seg[4*MAX_N];
int arr[MAX_N];
int lazy[4*MAX_N];
int mp[MAX_N];
void build(int v, int tl , int tr){
    if(tl == tr){
        seg[v] = tl;
    }
    else{
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid+1, tr);
        seg[v] = min(seg[2*v], seg[2*v+1]);
    }
}

void push(int v){
    seg[2*v] += lazy[v];
    seg[2*v+1] += lazy[v];
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l , int r, int val){
    if(l > r){
        return;
    }
    if(l == tl && tr == r){
        seg[v] += val;
        lazy[v] += val;
        return;
    }
    push(v);
    int mid = (tr + tl) / 2;
    update(2*v, tl, mid, l, min(r, mid), val);
    update(2*v + 1, mid+1, tr, max(l, mid+1), r, val);
    seg[v] = min(seg[2*v], seg[2*v+1]);
}

int query(int v, int tl, int tr, int l , int r){
    if(l > r){
        return INT_MAX;
    }
    if(l == tl && tr == r){        
        return seg[v];
    }
    push(v);
    int mid = (tr + tl) / 2;
    return min(query(2*v, tl, mid, l, min(r, mid)), query(2*v + 1, mid+1, tr, max(l, mid+1), r));    
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i]; arr[i]--;
        mp[arr[i]] = i;
    }
    build(1, 0, n-1);
    for(int i = 0; i < n; i++){
        int j = i / 2;
        if(i % 2){
            cout << abs(query(1, 0, n-1, mp[n-j-1], mp[n-j-1]) - (n-j-1)) << endl;
            update(1, 0, n-1, mp[n-j-1], n-1, -1);
        }
        else{
            int q = query(1, 0, n-1, mp[j], mp[j]);
            cout << abs(q - j) << endl;
            update(1, 0, n-1, 0, mp[j], 1);
        }
        
    }

    
}