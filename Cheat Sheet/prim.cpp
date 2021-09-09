#include <bits/stdc++.h>
using namespace std;

// MST

// Prim's Algorithm

// O(E * logV) 

const int maxn = 1003;

int n;
vector<pair<int, int>> adjs[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool taken[maxn];
set<int> srcs;

void prim(int u){
    taken[u] = 1;
    for(auto x : adjs[u]){
        int v = x.second, w = x.first; // w is the weight
        if(!taken[v])
            pq.push({w, v});
    }
}

int main(){
    // read the graph
    for(int s : src)
        prim(s);
    int mst = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int u = p.second, w = p.first;
        if(taken[u])
            continue;
        mst += w;
        prim(u);
    }
    cout << mst << endl;
}