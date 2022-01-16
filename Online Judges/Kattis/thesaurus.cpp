/*
 * https://open.kattis.com/problems/thesaurus
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, m;
string essay[5003];

int v = 0;
string dict[10003];
map<string, int> id;
int gid(string name){
    if(id.find(name) != id.end())
        return id[name];
    dict[v] = name;
    return id[name] = v++;
}

vector<int> adj[10003];

bool vis[10003];
int c = 0, ms[10003];
map<string, int> comp;
void dfs(int u){
    vis[u] = 1;
    ms[c] = min(ms[c], int(dict[u].size()));
    comp[dict[u]] = c;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> essay[i];
    string x, y;
    while(m--){
        cin >> x >> y;
        int i = gid(x), j = gid(y);
        adj[i].push_back(j), adj[j].push_back(i);
    }
    for(int i = 0; i < v; i++)
        if(!vis[i]){
            ms[c] = INT_MAX;
            dfs(i);
            c++;
        }
    int ans = 0;
    for(int i = 0; i < n; i++){
        string word = essay[i];
        if(comp.find(word) != comp.end())
            ans += ms[comp[word]];
        else
            ans += word.size();
    }
    cout << ans << endl;
}