/*
 * https://quera.org/problemset/2888/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100003

int indeg[MAX_N], need[MAX_N];
int n, m, a, b;
vector<int> adj[MAX_N];
priority_queue<int> pq;
int res[MAX_N];
set<int> s;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++; need[b]++;
    }
    for (int i = 1; i <= n; ++i) {
        if(!indeg[i])
            pq.push(i);
    }
    int h = n;int cur;
    while(!pq.empty()){
        cur = pq.top(); pq.pop();
        if(distance(s.begin(), s.upper_bound(cur)) != indeg[cur]){
            cout << "No answer" << endl;
            return 0;
        }
        s.insert(cur);
        res[cur] = h; h--;
        for (auto v: adj[cur]) {
            need[v]--;
            if(!need[v]){
                pq.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << ((i == n) ? "\n" : " ");
    }
    return 0;
}
