/*
 * https://open.kattis.com/problems/amanda
 * Author: https://github.com/smh997/
 */

# include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n, m, color[maxn], vis[maxn];
vector<int> adj[maxn];

bool wr;

void dfs(int u, int c){
    color[u] = c;
    vis[u] = true;
    for(int v : adj[u]){
        if(color[v] == color[u])
            wr = true;
        else if(!vis[v])
            dfs(v, 1-c);
    }
}

int red, blue;

void dfs2(int u, int c){
    color[u] = c;
    if(c == 0)
        red++;
    else
        blue++;
    for(int v : adj[u]){
        if(color[v] == color[u])
            wr = true;
        else if(color[v] == 2)
            dfs2(v, 1-c);
    }
}

int main(){
    cin >> n >> m;
    fill_n(color, n, 2);
    while(m--){
        int x, y, w;
        cin >> x >> y >> w, x--, y--;
        if(w == 0){
            if(color[x] == 1 || color[y] == 1){
                cout << "impossible" << endl;
                return 0;
            }
            color[x] = color[y] = 0;
        }
        else if(w == 2){
            if(color[x] == 0 || color[y] == 0){
                cout << "impossible" << endl;
                return 0;
            }
            color[x] = color[y] = 1;
        }
        else
            adj[x].push_back(y), adj[y].push_back(x);
    }
    for(int i = 0; i < n; i++)
        if(color[i] != 2 && !vis[i]){
            wr = false;
            dfs(i, color[i]);
            if(wr){
                cout << "impossible" << endl;
                return 0;
            }
        }
    int ans = count(color, color + n, 1);
    for(int i = 0; i < n; i++)
        if(color[i] == 2){
            wr = false;
            red = 0, blue = 0;
            dfs2(i, 0);
            if(wr){
                cout << "impossible" << endl;
                return 0;
            }
            ans += min(red, blue);
        }
    cout << ans << endl;   
}