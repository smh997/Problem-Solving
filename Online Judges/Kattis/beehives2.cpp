/*
 * https://open.kattis.com/problems/beehives2
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, tmp = 0, mx = INT_MAX;
vector<vector<int>> adj(503);
int dist[503], parent[503];

void bfs(int i){
    queue<int> q;
    q.push(i);
    dist[i] = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for (auto nei: adj[front]) {
            if (dist[nei] == INT_MAX) {
                dist[nei] = dist[front] + 1;
                q.push(nei);
                parent[nei] = front;
            }
            else if (parent[front] != nei){
                mx = min(dist[front] + dist[nei] + 1, mx);
            }
        }
    }
}


int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        fill_n(dist, n, INT_MAX);
        fill_n(parent, n, -1);
        bfs(i);
    }
    cout << ((mx == INT_MAX) ? "impossible" : to_string(mx)) << endl;

    return 0;
}

