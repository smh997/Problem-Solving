#include <bits/stdc++.h>
using namespace std;

// MST

// Kruskal's Algorithm

// O(E * logV)

// Second Best Spanning Tree: Remove each edge in MST and re-run kruskal, get min
// Minimax path: path that minimizes max-edge-weight: path in ms tree

#define MAX_N 1003

int n, m;
int a, b, w;
vector<pair<int, pair<int, int>>> edgeList;
int parent[MAX_N];
int raank[MAX_N];

void initSets(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        raank[i] = 0;
    }
}

int findSet(int i){
    if(parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]); // Path Compression
}

inline bool inSameSets(int i, int j){
    return findSet(i) == findSet(j);
}

void mergeSets(int i, int j){
    int a = findSet(i);
    int b = findSet(j);
    if(a == b)
        return;
    if(raank[a] >= raank[b])
        parent[b] = a;
    else
        parent[a] = b;
    if(raank[a] == raank[b])
        raank[a]++;
}

int main(){
    // read the graph
    sort(edgeList.begin(), edgeList.end());
    int mst = 0;
    int forests = n;
    initSets(n);
    for (int i = 0; i < edgeList.size(); i++){
        if(forests == 1)
            break;
        pair<int, pair<int, int>> front = edgeList[i];
        if(!inSameSets(front.second.first, front.second.second)){
            mst += front.first;
            forests--;
            mergeSets(front.second.first, front.second.second);
        }
    }
    cout << mst << endl;
}
