/*
 * https://open.kattis.com/problems/brexit
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(200003);
int C,P,X,L, a, b;
bool visited[200003];
queue<int> q;
int const_edge[200003];
int edge[200003];

int main()
{
    cin>>C>>P>>X>>L;
    fill_n(visited, C+1, false);
    fill_n(edge, C+1, 0);fill_n(const_edge, C+1, 0);
    for (int i = 0; i < P; ++i) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edge[a]++;edge[b]++;
        const_edge[a]++;const_edge[b]++;
    }
    visited[L] = true;
    for (auto v : adj[L]) {
        q.push(v);
        edge[v]--;
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u])
            continue;
        if(edge[u]<=const_edge[u]/2){
            visited[u]= true;
            for(int j=0; j<adj[u].size();j++){
                int v = adj[u][j];
                edge[v]--;
                q.push(v);
            }
        }
    }
    if(!visited[X])
        cout<<"stay"<<endl;
    else
        cout<<"leave"<<endl;
    return 0;
}
