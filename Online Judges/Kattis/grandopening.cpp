/*
 * https://open.kattis.com/problems/grandopening
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int n, m;
map<string, int> mp;
vector<int> adj[10003];
bool vis[10003];
bool noniso[10003];
vector<string> adjstr[10003];
int indeg[10003], outdeg[10003];
string s, t;
int mm, c=0;

void dfs(int u){
    vis[u]=true;
    for (auto v: adj[u])
        if(!vis[v])
            dfs(v);
}

int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        cin>>s;mp[s]=i;
        cin>>mm;
        for (int j = 0; j < mm; ++j) {
            cin>>t;
            if(s==t)continue;
            adjstr[i].push_back(t);
        }
    }
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        for(auto ss : adjstr[i]){
            if(mp.find(ss)==mp.end()){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
            adj[i].push_back(mp[ss]);
            indeg[mp[ss]]++;
            outdeg[i]++;
            noniso[i] = noniso[mp[ss]]=true;
            flag = true;
        }
    }
    if(!flag){
        cout<<"FALSE ALARM"<<endl;
        return 0;
    }
    
    int mi = 0; int mo=0, moid;
    for (int i = 0; i < n; ++i) {
        if(abs(outdeg[i]-indeg[i])>1){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        if(outdeg[i] - indeg[i] == 1)
            mo++, moid=i;
        else if(outdeg[i] - indeg[i] == -1)
            mi++;
    }
    if(mi == 1 && mo == 1){
        dfs(moid);
        c++;
        for (int i = 0; i < n; ++i) {
            if(noniso[i] && !vis[i]){
                dfs(i);
                c++;
            }
        }
    }
    else if(mi==0 && mo==0){
        for (int i = 0; i < n; ++i) {
            if(noniso[i] && !vis[i]){
                dfs(i);
                c++;
            }
        }
    }
    if(c==1 && ((mi == 1 && mo == 1)|| (mi==0 && mo==0)))
        cout<<"POSSIBLE"<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
