/*
 * https://open.kattis.com/problems/undetected
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

struct circle{
    int x, y, r;
};

int n;
circle a[203];

vector<int> adj[203];
bool vis[203];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

bool judge(int k){
    for(int i = 0; i < n + 2; i++)
        adj[i].clear();
    fill_n(vis, n+2, false);
    for(int i = 2; i < k + 2; i++)
        if(a[i].x - a[i].r <= 0)
            adj[0].push_back(i), adj[i].push_back(0);
    for(int i = 2; i < k + 2; i++)
        if(a[i].x + a[i].r >= 200)
            adj[1].push_back(i), adj[i].push_back(1);
    for(int i = 2; i < k + 2; i++)
        for(int j = i + 1; j < k + 2; j++){
            int deltax = a[i].x - a[j].x, deltay = a[i].y - a[j].y;
            if(deltax * deltax + deltay * deltay <= (a[i].r + a[j].r) * (a[i].r + a[j].r))
                adj[i].push_back(j), adj[j].push_back(i);
        }
    dfs(0);
    return !vis[1];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i+2].x >> a[i+2].y >> a[i+2].r;
    int lo = 0, hi = n;
    while(lo < hi){
        int mid = (lo + hi) / 2 + (lo + hi) % 2;
        if(judge(mid))
            lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
}