/*
 * https://open.kattis.com/problems/mafija
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int indeg[500003], adj[500003];
int n, a;
int color[500003];

void dfs(int u, int col){
    color[u] = col;
    indeg[adj[u]]--;
    if(col == 1 || indeg[adj[u]] == 0){
        if(color[adj[u]] == -1){
            dfs(adj[u], 1 - col);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;a--;
        indeg[a]++;
        adj[i] = a;
        color[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        if(indeg[i] == 0 && color[i] == -1){
            dfs(i, 1);
        }
    }
    int mafia = 0, notvis = 0;
    for (int i = 0; i < n; ++i) {
        if(color[i] == 1){
            mafia++;
        }
        else if(color[i] == -1){
            notvis++;
        }
    }
    cout << mafia + notvis / 2 << endl;
    return 0;
}

