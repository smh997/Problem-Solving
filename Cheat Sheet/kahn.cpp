#include <bits/stdc++.h>
using namespace std;

// Topological Sort

// Kahn's Algorithm

// O(V + E)

#define MAX_N 100003

int n, m, a, b;
vector<int> adj[MAX_N];
int indeg[MAX_N];
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> topoList;

int main(){
    // read the graph
    for(int i = 0; i < n; i++)
        if(!indeg[i])
            pq.push(i);
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        topoList.push_back(cur);
        for(auto v: adj[cur]){
            indeg[v]--;
            if(!indeg[v])
                pq.push(v);
        }
    }
    if(topoList.size() != n)
        cout << "cycle" << endl;
    else for(int i = 0; i < topoList.size(); i++)
            cout << topoList[i] << " ";
}

