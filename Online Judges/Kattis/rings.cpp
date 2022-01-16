/*
 * https://open.kattis.com/problems/rings
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

struct ring{
    long long int x, y, r;
};

int n;
bool visited[103];
vector<int> adj[103];
double x, y, r;
ring rings[103];
int comp, res;
int compsize[103];

void dfs(int u){
    visited[u] = true;
    compsize[comp]++;
    for (auto v: adj[u])
        if(!visited[v])
            dfs(v);
}

bool check_connect(int i, int j){
    long long int dist = pow(rings[i].x - rings[j].x, 2) + pow(rings[i].y - rings[j].y, 2);
    long long int sum_r = pow(rings[i].r + rings[j].r, 2);
//    cerr << i << " " << j << " " << dist << " " << sum_r << endl;
//    cerr << rings[i].x << " " << rings[i].y << " " << rings[i].r << endl;
//    cerr << rings[j].x << " " << rings[j].y << " " << rings[j].r << endl;
    return dist <= sum_r && dist >= pow(max(rings[i].r, rings[j].r) - min(rings[i].r, rings[j].r), 2);
}

int main()
{
    
    while(cin >> n && n != -1){
        fill_n(visited, n, false);
        fill_n(compsize, n, 0);
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            cin >> x >> y >> r;
            rings[i].x = (int)(x*1000);
            rings[i].y = (int)(y*1000);
            rings[i].r = (int)(r*1000);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if(check_connect(i, j)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        comp = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            if(!visited[i]){
                dfs(i);
                comp++;
            }
        }
        for (int i = 0; i < comp; ++i) {
            res = max(res, compsize[i]);
        }
        cout << "The largest component contains " << res << " ring";
        if(res == 1){
            cout << "." << endl;
        }
        else{
            cout << "s." << endl;
        }
    }
    return 0;
}

