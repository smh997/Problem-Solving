/*
 * https://open.kattis.com/problems/kingofthewaves
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

bool visited[1003];
vector<int> adj[1003];
int n;
char ch;
vector<int> res;

void dfs(int u){
    visited[u] = true;
    for (auto v: adj[u]) {
        if(!visited[v]){
            dfs(v);
        }
    }
    res.push_back(u);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ch;
            if(ch == '1'){
                adj[i].push_back(j);
            }
            else if(ch == '0'){
                adj[j].push_back(i);
            }
        }
    }
    dfs(0);
    if(res.size() == n){
        for (auto v: res) {
            cout << v << " ";
        }
        cout << endl;
    }
    else{
        cout << "impossible" << endl;
    }
    return 0;
}

