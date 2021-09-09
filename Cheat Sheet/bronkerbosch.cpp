#include <bits/stdc++.h>
using namespace std;

// Finding All Maximal Cliques(Max Independent Sets)

// Bron Kerbosch's Algorithm

// O(3 ^ (V / 3))

const int maxn = 133;

int n, m, deg[maxn];
set<int> adj[maxn];
set<int> R, P, X;

void bron(){
    if(P.empty() && X.empty()){ // A Maximal Cilque found and is in Set R
        cout << "Clique found: ";
        for(int u : R)
            cout << u << " ";
        cout << endl;
        return;
    }
	if(P.empty())
		return;
    int u, degm = -1;
    for(int cand : P)
        if(deg[cand] > degm)
            u = cand, degm = deg[cand];
    for(int cand : X)
        if(deg[cand] > degm)
            u = cand, degm = deg[cand];
    set<int> PP = P;
    for(int nu : adj[u])
        PP.erase(nu);
    for(int v : PP){
        set<int> cR = R, cP = P, cX = X;
        R.insert(v);
        P.clear();
        X.clear();
        for(int nv : adj[v]){
            if(cP.find(nv) != cP.end())
                P.insert(nv);
            if(cX.find(nv) != cX.end())
                X.insert(nv);
        }
        bron();
        R = cR, P = cP, X = cX;
        P.erase(v);
        X.insert(v);
    }
}

int main(){
    // read the graph
    for(int i = 0; i < n; i++)
        deg[i] = adj[i].size(), P.insert(i);
    bron();
}