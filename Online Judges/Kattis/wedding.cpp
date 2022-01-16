/*
 * https://open.kattis.com/problems/wedding
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100

int n, m, a, b, nums = 1, scc = 0;
int dfs_low[MAX_N], dfs_num[MAX_N];
int compo[MAX_N];
vector<int> adj[MAX_N];
vector<int> s;
bool visited[MAX_N];
bool ans[MAX_N];

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
    int nn, mm, a, b;
    string x, y;
    cin >> nn >> mm;
    n = 2 * nn;
    s.clear();
    nums = 1;
    scc = 0;
    add_edge(0, 0);
    for (int i = 0; i < mm; ++i) {
        cin >> x >> y;
        a = stoi(x.substr(0, x.length()-1)), b = stoi(y.substr(0, y.length()-1));
        a *= 2, b *= 2;
        if(x == "0w" || y == "0w" || x == y)
            continue;
        if(x[x.length()-1] == 'w'){
            a++;
        }
        if(y[y.length()-1] == 'w'){
            b++;
        }
        add_edge(a^1, b^1);
        add_edge(b^1, a^1);
    }
    for (int i = 0; i < n; i++)
        if(!dfs_num[i])
            dfs(i);
    for (int i = 0; i < n; i+=2) {
        if(compo[i] == compo[i ^ 1]){
            cout << "bad luck" << endl;
            return 0;
        }
        ans[i / 2] = compo[i] > compo[i ^ 1];
    }
    for (int i = 2; i < n; i+=2) {
        if(ans[i/2]){
            cout << i/2 << "h" << " ";
        }
        else{
            cout << i/2 << "w" << " ";
        }
    }
    cout << endl;
    return 0;
}

