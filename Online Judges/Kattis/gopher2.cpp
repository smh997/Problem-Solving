/*
 * https://open.kattis.com/problems/gopher2
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

// Maximum Cardinality Bipartite Matching
// O(V * E)

const int maxn = 103;
const int maxm = 103;

// n is |left set|, m is |right set|, edges are from left set to right set
int n, m, s, v;
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

double gophers[103][2];
double holes[103][2];

bool check(int i, int j){
    double dist = hypot(gophers[i][0] - holes[j][0], gophers[i][1] - holes[j][1]);
    return dist / v > 1.0 * s;
}

int main(){
    while(cin >> n >> m >> s >> v){
        for (int i = 0; i < n; ++i) {
            cin >> gophers[i][0] >> gophers[i][1];
            adjs[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            cin >> holes[i][0] >> holes[i][1];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(!check(i, j))
                    adjs[i].push_back(j);
            }
        }
        int ans = 0;
        fill_n(match, m, -1);
        for(int i = 0; i < n; i++){
            fill_n(vis, n, 0);
            ans += aug(i);
        }
        cout << n - ans << endl;
    }
    
}
