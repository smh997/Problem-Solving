/*
 * https://quera.org/problemset/6404/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

bool visited[600003];
vector<vector<int>> adj(600003);
int need[600003];
queue<int> qu;
vector<int> mojood;
int n, m, k, res = 0, p, q;

void bfs(){
    int u;
    res = m;
    for (int i = 0; i < m; ++i) {
        visited[mojood[i]] = true;
        qu.push(mojood[i]);
    }
    while(!qu.empty()){
        u = qu.front();
        qu.pop();
        for (auto v : adj[u]) {
            if(!visited[v]){
                if(need[v] > 1){
                    need[v]--;
                    continue;
                }
                if(v <= 300000){
                    res++;
                    mojood.push_back(v);
                }
                visited[v] = true;
                qu.push(v);
            }
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    mojood.resize(m);
    fill_n(need, n+1, 0);
    fill_n(visited, n+1, false);
    for (int i = 0; i < m; ++i) {
        cin>>mojood[i];
    }
    for (int i = 0; i < k; ++i) {
        cin>>p>>q;
        int pa, qa;
        need[300001+i] = 0; visited[300001+i]= false;
        for (int j = 0; j < p; ++j) {
            cin>>pa;
            adj[pa].push_back(300001+i);
            need[300001+i]++;
        }
        for (int j = 0; j < q; ++j) {
            cin>>qa;
            adj[300001+i].push_back(qa);
        }
    }
    bfs();
    cout<<res<<endl;
    sort(mojood.begin(), mojood.end());
    for (auto v : mojood) {
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}

