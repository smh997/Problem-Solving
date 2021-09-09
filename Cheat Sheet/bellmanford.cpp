#include <bits/stdc++.h>
using namespace std;

// SSSP, -ve weight

// Bellman Ford's Algorithm

// O(V ^ 3)

#define inf INT_MAX // INT_MAX is important

int n, src;
struct edge{
    int u, v, w; // edge from u to v with weight w
} edges[103];
long long int dis[103]; // long long int is important

int main(){
    // read the graph
    fill_n(dis, n, inf);
    dis[src] = 0;
    for(int i = 0; i < n-1; i++)
        for(edge e : edges)
            if(dis[e.u] != inf)
                dis[e.v] = min(dis[e.v], dis[e.u] + e.w);
    for(int i = 0; i < n-1; i++)
        for(edge e : edges)
            if(dis[e.u] != inf && dis[e.u] + e.w < dis[e.v])
                dis[e.v] = -inf;
    // nodes with dis = inf are not reachable
    // nodes with dis = -inf are reachable from at least one negative cycle
}