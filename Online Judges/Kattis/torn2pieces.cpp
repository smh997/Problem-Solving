/*
 * https://open.kattis.com/problems/torn2pieces
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 32 * 32 + 3;

int n, cnt = 0;
string names[MAX_N];
map<string, int> m;

int id(string s){
    if(m.find(s) != m.end())
        return m[s];
    names[cnt] = s;
    m[s] = cnt;
    return cnt++;
}

vector<int> adj[MAX_N];
int dist[MAX_N];
int parent[MAX_N];
queue<int> q;

int main(){
    cin >> n;
    string line, x, y;
    getline(cin, line);
    for(int i = 0; i < n; i++){
        getline(cin, line);
        stringstream ss(line);
        ss >> x;
        int a = id(x);
        while(ss >> y){
            int b = id(y);
            adj[a].push_back(b), adj[b].push_back(a);
        }
    }
    cin >> x >> y;
    if(m.find(x) == m.end() || m.find(y) == m.end()){
        cout << "no route found" << endl;
        return 0;
    }
    int s = m[x], e = m[y];
    fill_n(dist, cnt, INT_MAX);
    dist[s] = 0;
    parent[s] = -1;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(dist[v] == INT_MAX){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    if(dist[e] == INT_MAX)
        cout << "no route found" << endl;
    else{
        vector<int> path;
        int it = e;
        while(it != -1){
            path.push_back(it);
            it = parent[it];
        }
        for(int i = path.size()-1; i >= 0; i--)
            cout << names[path[i]] << " ";
        cout << endl;
    }   
}