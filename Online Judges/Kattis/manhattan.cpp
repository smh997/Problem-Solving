/*
 * https://open.kattis.com/problems/manhattan
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 123

int n, m, a, b, nums = 1, scc = 0;
int dfs_low[MAX_N], dfs_num[MAX_N];
int compo[MAX_N];
vector<int> adj[MAX_N];
vector<int> s;
bool visited[MAX_N];

void dfs(int u){
    dfs_num[u] = dfs_low[u] = nums++;
    s.push_back(u);
    visited[u] = true;
    for(auto v: adj[u]){
        if(!dfs_num[v])
            dfs(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        scc++;
        while(true){
            int w = s.back();
            s.pop_back();
            visited[w] = false;
            compo[w] = scc;
            if(w == u)
                break;
        }
    }
}



void add_edge(int a, int b){
    adj[a ^ 1].push_back(b);
    adj[b ^ 1].push_back(a);
}


int main()
{
    int nn, ss, aa, mm, x1, y1, x2, y2;
    cin >> nn;
    while(nn--){
        cin >> ss >> aa >> mm;
        n = (ss + aa) * 2;
        s.clear();
        nums = 1;
        scc = 0;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            dfs_num[i] = dfs_low[i] = 0;
            visited[i] = false;
        }
        for (int i = 0; i < mm; ++i) {
            cin >> y1 >> x1 >> y2 >> x2;
            x1--, x2--, y1--, y2--;
            x1 *= 2, x2 *= 2, y1 *= 2, y2 *= 2;
            y1 += 2 * aa, y2 += 2 * aa;
            if(x1 == x2 && y1 == y2)
                continue;
            if(x1 == x2){
                if(y1 > y2)
                    add_edge(x2 ^ 1, x2 ^ 1);
                else
                    add_edge(x2, x2);
            }
            else if(y1 == y2){
                if(x1 > x2)
                    add_edge(y1 ^ 1, y1 ^ 1);
                else
                    add_edge(y1, y1);
            }
            else{
                if(x1 < x2 && y1 < y2)
                    add_edge(y1, x1), add_edge(y1, y2), add_edge(x2, x1), add_edge(x2, y2);
                else if(x1 < x2 && y1 > y2){
                    add_edge(x1 ^ 1, y1), add_edge(x1 ^ 1, x2 ^ 1), add_edge(y2, y1), add_edge(y2, x2 ^ 1);
                }
                else if(x1 > x2 && y1 < y2){
                    add_edge(y1 ^ 1, x1), add_edge(y1 ^ 1, y2 ^ 1), add_edge(x2, x1), add_edge(x2, y2 ^ 1);
                }
                else{
                    add_edge(y1 ^ 1, x1 ^ 1), add_edge(x2 ^ 1, x1 ^ 1), add_edge(y1 ^ 1, y2 ^ 1), add_edge(x2 ^ 1, y2 ^ 1);
                }
            }
        }
        for (int i = 0; i < n; i++)
            if(!dfs_num[i])
                dfs(i);
        bool flag = false;
        for (int i = 0; i < n; i+=2) {
            if(compo[i] == compo[i ^ 1]){
                cout << "No" << endl;
                flag = true;
                break;
            }
        }
        if(flag)
            continue;
        cout << "Yes" << endl;
    }
    return 0;
}

