/*
 * https://open.kattis.com/problems/ragingriver
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define num long long int

const int maxn = 1503;
const int inf = INT_MAX;

int N, M, src, sink;
bool found[maxn];
int cap[maxn][maxn], flow[maxn][maxn], par[maxn], dis[maxn], picked[maxn];
num cost[maxn][maxn];

bool aug(){
    fill_n(found, N, false);
    fill_n(dis, N + 1, inf);
    int it = src;
    dis[it] = 0;
    while(it != N){
        int best = N;
        found[it] = true;
        for(int k = 0; k < N; k++){
            if(found[k])
                continue;
            if(flow[k][it] != 0){
                int val = dis[it] + picked[it] - picked[k] - cost[k][it];
                if(dis[k] > val)
                    dis[k] = val, par[k] = it;
            }
            if(flow[it][k] < cap[it][k]){
                int val = dis[it] + picked[it] - picked[k] + cost[it][k];
                if(dis[k] > val)
                    dis[k] = val, par[k] = it;
            }
            if(dis[k] < dis[best])
                best = k;
        }
        it = best;
    }
    for(int k = 0; k < N; k++)
        if(dis[k] != inf)
            picked[k] += dis[k];
    return found[sink];
}

pair<int, num> mincost_maxflow(int k){
    int tf = 0;
    num tc = 0;
    while(tf < k && aug()){
        int f = k - tf;
        for(int x = sink; x != src; x = par[x]){
            if(flow[x][par[x]] != 0)
                f = min(f, flow[x][par[x]]);
            else
                f = min(f, cap[par[x]][x] - flow[par[x]][x]);
        }
        tf += f;
        for(int x = sink; x != src; x = par[x]){
            if(flow[x][par[x]] != 0){
                flow[x][par[x]] -= f;
                tc -= cost[x][par[x]] * f;
            }
            else{
                flow[par[x]][x] += f;
                tc += cost[par[x]][x] * f;
            }   
        }
    }
    return {tf, tc};
}

int P, L, R, x, y;

int main(){
    cin >> P >> R >> L;
    src = R, sink = R + 1;
    N = R+2;
    for (int i = 0; i < L; ++i) {
        cin >> x >> y;
        if(x == -2)
            x = src;
        else if(x == -1)
            x = sink;
        if(y == -2)
            y = src;
        else if(y == -1)
            y = sink;
        cost[x][y] = cost[y][x] = cap[x][y] = cap[y][x] = 1;
    }
    auto ans = mincost_maxflow(P);
    if(ans.first < P){
        cout << P - ans.first << " people left behind" << endl;
    }
    else{
        cout << ans.second << endl;
    }
}
