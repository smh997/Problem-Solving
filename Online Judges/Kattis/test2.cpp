/*
 * https://open.kattis.com/problems/test2
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n, nums =0, scc = 0;
vector<int> st;
int dnum[263], dlow[263];
bool visited[263];
vector<vector<string>> res;
string s[5];
map<string, int> mp;
string nodes[263];

void tarjan(int u){
    dnum[u] = dlow[u] = nums++;
    visited[u] = true; st.push_back(u);
    for (auto v: adj[u]) {
        if(dnum[v]==-1){
            tarjan(v);
        }
        if(visited[v]){
            dlow[u]=min(dlow[u], dlow[v]);
        }
    }
    if(dnum[u] == dlow[u]){
        int w;
        vector<string> vv;
        while(true){
            w = st.back();
            st.pop_back();
            visited[w] = false;
            vv.push_back(nodes[w]);
            if(u==w)
                break;
        }
        res.push_back(vv);
        scc++;
    }
}


int main()
{
    while(true){
        cin>>n;
        if(!n)
            break;
        adj.clear();
        adj.resize(n*5);
        mp.clear();
        fill_n(nodes, n*5, "");
        nums = scc = 0;
        int k = 0;
        string source;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin>>s[j];
                if(mp.find(s[j])==mp.end()){
                    nodes[k] = s[j];
                    mp[s[j]] = k++;
                }
            }
            cin>>source;
            for (int j = 0; j < 5; ++j) {
                if(source==s[j])
                    continue;
                adj[mp[source]].push_back(mp[s[j]]);
            }
        }
        fill_n(dnum, k, -1);
        fill_n(dlow, k, -1);
        fill_n(visited, k, false);
        res.clear();
        for (int i = 0; i < k; ++i) {
            if(dnum[i]==-1){
                tarjan(i);
            }
        }
        for (int i = 0; i < scc; ++i) {
            sort(res[i].begin(), res[i].end());
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < scc; ++i) {
            for (auto u : res[i]) {
                cout<<u<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}

