#include <bits/stdc++.h>
using namespace std;

// Minimum Cost Maximum Flow

#define num long long int

const int maxn = 253;
const num inf = LLONG_MAX;

int N, M, src, sink;
bool found[maxn];
int cap[maxn][maxn], flow[maxn][maxn], par[maxn];
num picked[maxn], dis[maxn], cost[maxn][maxn];

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
                num val = dis[it] + picked[it] - picked[k] - cost[k][it];
                if(dis[k] > val)
                    dis[k] = val, par[k] = it;
            }
            if(flow[it][k] < cap[it][k]){
                num val = dis[it] + picked[it] - picked[k] + cost[it][k];
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

pair<int, num> mincost_maxflow(){
    int tf = 0;
    num tc = 0;
    while(aug()){
        int f = INT_MAX;
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

int main(){
    cin >> N >> M >> src >> sink;
    int x, y;
    while(M--)
        cin >> x >> y >> cap[x][y] >> cost[x][y];
    auto ans = mincost_maxflow();
    cout << ans.first << " " << ans.second << endl;
}