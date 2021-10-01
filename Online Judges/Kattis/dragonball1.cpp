/*
 * https://open.kattis.com/problems/dragonball1
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define inf LLONG_MAX
const int maxn = 2e5 + 3;

int n, m, tr[8+3];
num tmp[maxn], dist[10][10], dp[(1<<8)+3][8+3];
vector<pair<int, num>> adj[maxn];

void dijkstra(int t1){
    int s = tr[t1];
    fill_n(tmp, n, inf);
    priority_queue<pair<num, int>, vector<pair<num, int>>, greater<pair<num, int>>> dij;
    tmp[s] = 0, dij.push({0, s});
    while(!dij.empty()){
        int u = dij.top().second;
        num w = dij.top().first;
        dij.pop();
        if(tmp[u] < w)
            continue;
        for(pair<int, num> v : adj[u])
            if(w + v.second < tmp[v.first])
                tmp[v.first] = w + v.second, dij.push({tmp[v.first], v.first});     
    }
    for(int t2 = 0; t2 < 8; t2++)
        dist[t1][t2] = tmp[tr[t2]];
}


int main(){
    cin >> n >> m;
    int x, y;
    num w;
    while(m--)
        cin >> x >> y >> w, adj[x-1].push_back({y-1, w}), adj[y-1].push_back({x-1, w});
    tr[0] = 0;
    for(int i = 1; i < 8; i++)
        cin >> tr[i], tr[i]--;
    for(int i = 0; i < 8; i++)
        dijkstra(i);
    for(int mask = 1; mask < (1<<7); mask++)
        for(int node = 0; node < 7; node++)
            if(mask & (1 << node)){
                if(mask == 1 << node)
                    dp[mask][node] = dist[0][node+1];
                else{
                    dp[mask][node] = inf;
                    for(int prevy = 0; prevy < 7; prevy++)
                        if(prevy != node && (mask & (1 << prevy))){
                            num subp = dp[mask - (1 << node)][prevy];
                            num di = dist[prevy+1][node+1];
                            if(subp != inf && di != inf)
                                dp[mask][node] = min(dp[mask][node], subp + di);
                        }
                }
            }
    num ans = inf;
    for(int i = 0; i < 7; i++)
        ans = min(ans, dp[(1<<7)-1][i]);
    cout << (ans == inf ? -1 : ans) << endl;
}
