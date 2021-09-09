#include <bits/stdc++.h>
using namespace std;

// SSSP, Dijkstra

// Dijkstra's Algorithm

// O(V + E * logV)

#define inf INT_MAX

int n, src;
vector<pair<int, int>> adjs[103]; // {weight, dst}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dis[103];

int main(){
    // read the graph
    fill_n(dis, n, inf);
    pq.push({0, src});
    dis[src] = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int d = p.first, u = p.second;
        if(dis[u] < d) // lazy delete
            continue;
        for(auto x : adjs[u])
            if(dis[x.second] > dis[u] + x.first) // relaxation
                dis[x.second] = dis[u] + x.first, pq.push({dis[x.second], x.second});
    }
}