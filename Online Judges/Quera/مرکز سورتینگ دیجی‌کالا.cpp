/*
 * https://quera.org/problemset/136481/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;

int n, m, k, r, c1, c2, cc = 0;
bool visited[503][503];
vector<pair<int, int>> adj[503][503];
bool roller[503][503];
pair<int, int> mvs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pair<int, int>> members[503 * 503];

void dfs(int i, int j){
    visited[i][j] = true;
    members[cc].push_back({i, j});
    for(pair<int, int> nei: adj[i][j]){
        if (!visited[nei.first][nei.second]){
            dfs(nei.first, nei.second);
        }
    }
}


int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        cin >> r >> c1 >> c2;
        for (int j = c1 - 1; j < c2; ++j) {
            roller[r - 1][j] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (roller[i][j]){
                for (pair<int, int> mv : mvs){
                    pair<int, int> nxt = {i + mv.first, j + mv.second};
                    if (nxt.first < n && nxt.first >= 0 && nxt.second < m && nxt.second >= 0 && roller[nxt.first][nxt.second]){
                        adj[i][j].push_back(nxt);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(!visited[i][j]){
                dfs(i, j);
                cc++;
            }
        }
    }
    int mxarea = 0;
    for (int i = 0; i < cc; ++i) {
        int mir = 1000, mic = 1000, mxr = -1, mxc = -1;
        for (pair<int ,int> member: members[i]) {
            mir = min(mir, member.first);
            mxr = max(mxr, member.first);
            mic = min(mic, member.second);
            mxc = max(mxc, member.second);
        }
        int area = (mxr - mir + 1) * (mxc - mic + 1);
        mxarea = max(mxarea, area);
    }
    cout << mxarea << endl;
    return 0;
}

