/*
 * https://open.kattis.com/problems/rainbowroads
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
bool res;
vector<vector<pair<int, int>>> adj(50003, vector<pair<int, int>>());
vector<set<int>> has_color(50003, set<int>()); 
vector<pair<int, int>> candid; 
bool visited[50003]; 
bool good[50003]; 

bool dfs(int start, int prev_w){
    visited[start] = true; // visit node
    good[start] = false;
    for (int i = 0; i < adj[start].size(); ++i) {
        int nex = adj[start][i].first;
        int w = adj[start][i].second;
        if(visited[nex])
            continue;
        if(w==prev_w) 
            return true;
        res = dfs(nex, w);
        if(res) return true;
    }
    return false;
}


void solve(){
    for (int i = 0; i < candid.size(); ++i) {
        int start = candid[i].first;
        int w = candid[i].second;
        if(visited[start])
            continue;
        visited[start] = true;
        for (int j = 0; j < adj[start].size(); ++j) {
            if(adj[start][j].second == w)
                res = dfs(adj[start][j].first, w);
            if(res) return;
        }
        visited[start] = false;
    }
}

int main()
{
    fill_n(good, 50003, true);
    fill_n(visited, 50003, false);
    cin>>n;
    int a, b, c;
    for (int i = 0; i < n-1; ++i) {
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
        if(has_color[a].find(c)!=has_color[a].end())
            candid.push_back(make_pair(a, c));
        else
            has_color[a].insert(c);
        if(has_color[b].find(c) != has_color[b].end())
            candid.push_back(make_pair(b, c));
        else
            has_color[b].insert(c);
    }
    solve();
    if(res)
        cout<<0<<endl;
    else{
        vector<int> ans;
        for (int i = 1; i <= n; ++i)
            if(good[i])
                ans.push_back(i);
        cout<<ans.size()<<endl;
        for(auto a : ans)
            cout<<a<<endl;
    }
    return 0;
}
