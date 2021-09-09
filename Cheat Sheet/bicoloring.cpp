#include <bits/stdc++.h>
using namespace std;

// Graph Bi-Coloring (Check)

// O(V + E)

const int maxn = 500003;

int n, m;
vector<int> adjs[maxn];
int color[maxn]; // 0 is red, 1 is blue and 2 is without color
bool bicolorable = true;

void dfs(int u, int c){
    color[u] = c;
    for(int x : adjs[u]){
        if(color[x] == 2)
            dfs(x, 1 - c); // swap the color!
        else if(color[x] == color[u])
            bicolorable = false;
    }
}

int main(){
    // read the graph
    fill_n(color, n, 2);
    for(int i = 0; i < n; i++)
        if(color[i] == 2)
            dfs(i, 1); // or dfs(i, 0)
}