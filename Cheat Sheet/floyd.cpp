#include <bits/stdc++.h>
using namespace std;

// APSP

// Floyd Warshall's Algorithm

// O(V ^ 3)

// Minimax path (max edge weight should be minimum): sp[i][j] = min(sp[i][j], max(sp[i][k], sp[k][j]))
// Shortest cycle: Initially set sp[i][i] = inf then the answer is min(sp[i][i]) for all i
// Diameter (max sp): max(sp[i][j]) for all i and j
// SCC: if sp[i][j] != inf and sp[j][i] != inf then i and j are in the same scc     

#define inf INT_MAX
#define num long long int

const int maxn = 153;

int n, e, q;
num sp[maxn][maxn];
int par[maxn][maxn];

void path(int i, int j){
    int k = par[i][j];
    if(k == -1)
        cout << i << " ";
    else
        path(i, k), path(k, j);
}

int main(){
    cin >> n >> e;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(i == j)
                sp[i][j] = 0;
            else
                sp[i][j] = inf;
            par[i][j] = -1;
        }
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w; // edges are directed
        sp[u][v] = min(sp[u][v], (num)w);
    }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(sp[i][k] != inf && sp[k][j] != inf && sp[i][k] + sp[k][j] < sp[i][j])
                    sp[i][j] = sp[i][k] + sp[k][j], par[i][j] = k;
    // check for paths with negative cycle:
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                if(sp[i][k] != inf && sp[k][j] != inf && sp[k][k] < 0)
                    sp[i][j] = -inf;
    int src, dst;
    cin >> src >> dst;
    cout << sp[src][dst] << endl;
    // print path:
    path(src, dst);
    cout << dst << endl;
}