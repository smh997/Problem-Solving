#include <bits/stdc++.h>
using namespace std;

// Maximum Cardinality Bipartite Matching
// O(V * E)

const int maxn = 1003;
const int maxm = 1003;

// n is |left set|, m is |right set|, edges are from left set to right set
int n, m;
vector<int> adjs[maxn];
bool vis[maxn];
int match[maxm]; // if match[v] = u then u from left set is matched with v from right set

int aug(int u){
    if(vis[u])  
        return 0;
    vis[u] = 1;
    for(int v : adjs[u])
        if(match[v] == -1 || aug(match[v])){
            match[v] = u;
            return 1;
        }
    return 0;
}

int main(){
    // read the graph
    int ans = 0;
    fill_n(match, m, -1);
    for(int i = 0; i < n; i++){
        fill_n(vis, n, 0);
        ans += aug(i);
    }
    cout << ans << endl;
}