/*
 * https://open.kattis.com/problems/decisions
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = (1 << 20 + 3);
int n, heap[maxn], cnt[maxn], ans = 0;

void build(int u){
    if(u >= (1 << n))
        return;
    build(2 * u);
    build(2 * u + 1);
    heap[u] = heap[2 * u] + heap[2 * u + 1];
    cnt[u] = cnt[2 * u] + cnt[2 * u + 1];
}

void pre_order(int u){
    ans++;
    if(!heap[u] || heap[u] == cnt[u])
        return;
    pre_order(2 * u);
    pre_order(2 * u + 1);
}

int main(){
    cin >> n;
    for(int i = 0; i < (1 << n); i++){
        int x, h = 1;
        cin >> x;
        for(int j = 0; j < n; j++){
            h *= 2;
            if(i & (1 << j))
                h += 1;
        }
        heap[h] = x, cnt[h] = 1;
    }
    build(1);
    pre_order(1);
    cout << ans << endl;
}