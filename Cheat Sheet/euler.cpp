#include <bits/stdc++.h>
using namespace std;

// Eulerian Graph

// Euler's Algorithm

// O(V + E)

// This code is for a directed graph and prints either eulerian tour or path

const int maxn = 1003;

int n;
vector<pair<string, int>> adjs[maxn]; // edges are labeled with string
int indeg[maxn], outdeg[maxn];

vector<int> eulerian_nodes;
vector<string> eulerian_edges;

void euler(int u){
    while(!adjs[u].empty()){
        auto x = *adjs[u].rbegin();
        adjs[u].pop_back();
        euler(x.second);
        eulerian_edges.push_back(x.first);
    }
    eulerian_nodes.push_back(u);
}

int check_eulerian(){ // -1 is for a non-eulerian graph, else start node is returned
    int oddcnt = 0;
    vector<int> oddv;
    for(int i = 0; i < n; i++)
        if(indeg[i] != outdeg[i])
            oddcnt++, oddv.push_back(i);
    if(oddcnt == 1 || oddcnt > 2)
        return -1;
    if(oddcnt == 0){
        for(int i = 0; i < n; i++)
            if(adjs[i].size() > 0)
                return i;
    }
    // oddcnt is 2:
    int u1 = oddv[0], u2 = oddv[1];
    if((indeg[u1] - outdeg[u1]) * (indeg[u2] - outdeg[u2]) != -1)
        return -1;
    if(outdeg[u1] > indeg[u1])
        return u1;
    return u2;
}

int main(){
    // read the graph
    int s = check_eulerian();
    if(s == -1){
        cout << "impossible" << endl;
        return 0;
    }
    euler(s);
    for(int i = 0; i < n; i++)
        if(!adjs[i].empty()){
            cout << "impossible" << endl;
            return 0;
        }
    reverse(eulerian_nodes.begin(), eulerian_nodes.end());
    reverse(eulerian_edges.begin(), eulerian_edges.end());
    // print the path
}