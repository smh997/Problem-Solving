/*
 * https://quera.org/problemset/82387/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num inf = LLONG_MIN;
const int maxn = 1e5 + 3;

int n, s, indl[4 * maxn], indr[4 * maxn], heapl[maxn], heapr[maxn];
num x[maxn], h[maxn], psuml[maxn], psumr[maxn], segl[4 * maxn], segr[4 * maxn];

void buildl(int v, int tl, int tr){
    if(tl == tr)
        segl[v] = h[tl] - psuml[tl], indl[v] = tl, heapl[tl] = v;
    else{
        int mid = (tl + tr) / 2;
        buildl(2 * v, tl, mid);
        buildl(2 * v + 1, mid + 1, tr);
        segl[v] = segl[2 * v], indl[v] = indl[2 * v];
        if(segl[2 * v + 1] > segl[v])
            segl[v] = segl[2 * v + 1], indl[v] = indl[2 * v + 1];
    }
}

void buildr(int v, int tl, int tr){
    if(tl == tr)
        segr[v] = h[tl] - psumr[tl], indr[v] = tl, heapr[tl] = v;
    else{
        int mid = (tl + tr) / 2;
        buildr(2 * v, tl, mid);
        buildr(2 * v + 1, mid + 1, tr);
        segr[v] = segr[2 * v + 1], indr[v] = indr[2 * v + 1];
        if(segr[2 * v] > segr[v])
            segr[v] = segr[2 * v], indr[v] = indr[2 * v];
    }
}

void updatel(int pos, num val){
    int v = heapl[pos];
    segl[v] = val, v /= 2;
    while(v){
        segl[v] = segl[2 * v], indl[v] = indl[2 * v];
        if(segl[2 * v + 1] > segl[v])
            segl[v] = segl[2 * v + 1], indl[v] = indl[2 * v + 1];
        v /= 2;
    }
}

void updater(int pos, num val){
    int v = heapr[pos];
    segr[v] = val, v /= 2;
    while(v){
        segr[v] = segr[2 * v + 1], indr[v] = indr[2 * v + 1];
        if(segr[2 * v] > segr[v])
            segr[v] = segr[2 * v], indr[v] = indr[2 * v];
        v /= 2;
    }
}

pair<num, int> queryl(int v, int tl, int tr, int l, int r){
    if(l > r)
        return {inf, 0};
    if(tl == l && tr == r)
        return {segl[v], indl[v]};
    int mid = (tl + tr) / 2;
    pair<num, int> lq = queryl(2 * v, tl, mid, l, min(r, mid));
    pair<num, int> rq = queryl(2 * v + 1, mid+1, tr, max(l, mid+1), r);
    if(lq.first >= rq.first)
        return lq;
    return rq;
}

pair<num, int> queryr(int v, int tl, int tr, int l, int r){
    if(l > r)
        return {inf, 0};
    if(tl == l && tr == r)
        return {segr[v], indr[v]};
    int mid = (tl + tr) / 2;
    pair<num, int> lq = queryr(2 * v, tl, mid, l, min(r, mid));
    pair<num, int> rq = queryr(2 * v + 1, mid+1, tr, max(l, mid+1), r);
    if(rq.first >= lq.first)
        return rq;
    return lq;
}

num ans = 0;

int main(){
    cin >> n >> s, s--;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> h[i];
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i < n; i++)
        psuml[i] = psuml[i-1] + x[i] - x[i-1];
    for(int i = n-1; i >= 0; i--)
        psumr[i] = psumr[i+1] + x[i+1] - x[i];
    buildl(1, 0, n-1);
    buildr(1, 0, n-1);
    for(int i = 0; i < n-1; i++){
        updatel(s, inf);
        updater(s, inf);
        pair<num, int> ql = {inf, 0}, qr = {inf, 0};
        int choose;
        if(s < n-1)
            ql = queryl(1, 0, n-1, s+1, n-1);
        if(s > 0)
            qr = queryr(1, 0, n-1, 0, s-1);
        if(ql.first == inf)
            choose = qr.second;
        else if(qr.first == inf)
            choose = ql.second;
        else{
            num lval = ql.first + psuml[s], rval = qr.first + psumr[s];
            if(lval > rval)
                choose = ql.second;
            else if(rval > lval)
                choose = qr.second;
            else{
                if(x[ql.second] - x[s] < x[s] - x[qr.second])
                    choose = ql.second;
                else
                    choose = qr.second;
            }
        }
        ans += abs(x[choose] - x[s]), s = choose;
    }
    cout << ans << endl;
}