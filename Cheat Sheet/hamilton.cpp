#include <bits/stdc++.h>
using namespace std;

// Hamiltonian Path in DAG

// Hamiltonian Path exists if and only if DAG has one unique Topological Order

// O(V + E)

int n;
int indeg[1003];
vector<int> adj[1003];

vector<int> path;
bool hamiltonian(){
	queue<int> candidate;
    for(int i = 0; i < n; i++)
        if(!indeg[i])
            candidate.push(i);
    while(!candidate.empty()){
        if(candidate.size() > 1)
            return false;
        int u = candidate.front();
        candidate.pop();
        path.push_back(u);
        for(int v : adj[u]){
            indeg[v]--;
            if(!indeg[v])
                candidate.push(v);
        }
    }
	return true;
}