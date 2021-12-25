/*
 * https://open.kattis.com/problems/molekule
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(100003);
int color[100003];
int n, a, b;
pair<int ,int> cov[100003];



int main()
{
    cin>>n;
    fill_n(color, n+1, INT_MAX);
    for (int i = 0; i < n-1; ++i) {
        cin>>cov[i].first>>cov[i].second;
        adj[cov[i].first].push_back(cov[i].second);
        adj[cov[i].second].push_back(cov[i].first);
    }
    queue<int> q;
    q.push(1);
    color[1] = 0;
    int u;
    while(!q.empty()){
        u = q.front();q.pop();
        for (auto v : adj[u]) {
            if(color[v]==INT_MAX){
                color[v] = 1 - color[u];
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n-1; ++i) {
        cout<<((color[cov[i].first])?"1":"0")<<endl;
    }
    return 0;
}

