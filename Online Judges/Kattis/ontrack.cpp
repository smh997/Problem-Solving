/*
 * https://open.kattis.com/problems/ontrack
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[10003];

bool vis[10003];
multiset<int> ccs;
int cc;

void dfs(int u){
    vis[u] = true;
    cc++;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    int x, y;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    n++;
    int best = 0, ans = 0;
    for(int r = 0; r < n; r++){
        if(adj[r].size() == 1)
            continue;
        fill_n(vis, n, false);
        vis[r] = true;
        ccs.clear();
        int sum = 0;
        for(int u : adj[r]){
            cc = 0;
            dfs(u);
            ccs.insert(cc);
            sum += cc;
        }
        if(ccs.size() >= 2){
            int curr = 0;
            for(int x : ccs)
                curr += x * (sum - x);
            if(curr > best){
                best = curr;
                ans = best - (*prev(ccs.end())) * (*prev(ccs.end(), 2)) * 2;
            }
            else if(curr == best){
                int curr2 = best - (*prev(ccs.end())) * (*prev(ccs.end(), 2)) * 2;
                if(curr2 < ans)
                    ans = curr2;
            }
        }
    }
    cout << best / 2 << " " << ans / 2  << endl;
}