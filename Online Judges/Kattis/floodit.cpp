/*
 * https://open.kattis.com/problems/floodit
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int t, n;
int grid[23][23];
int mx, mxid;
int used[10], cnt;
bool visited[23][23];
int dirr[4] = {0, 1, 0, -1};
int dirc[4] = {1, 0, -1, 0};
bool inrange(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < n;
}
vector<pair<int, int>> vis;
vector<pair<int, int>> newvis[7];
bool newvisited[7][23][23];

void dfs(int ur, int uc, int color){
    newvisited[color][ur][uc] = true;
    newvis[color].push_back({ur, uc});
    cnt++;
    for (int i = 0; i < 4; ++i) {
        int r = ur + dirr[i], c = uc + dirc[i];
        if(inrange(r, c) && !newvisited[color][r][c] && grid[r][c] == color){
            dfs(r, c, color);
        }
    }
}

void dfs2(int ur, int uc, int color){
    visited[ur][uc] = true;
    vis.push_back({ur, uc});
    for (int i = 0; i < 4; ++i) {
        int r = ur + dirr[i], c = uc + dirc[i];
        if(inrange(r, c) && !visited[r][c] && grid[r][c] == color){
            dfs2(r, c, color);
        }
    }
}

char ch;
int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        fill_n(used, 7, 0);
        vis.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> ch;
                grid[i][j] = ch - '0';
                visited[i][j] = false;
            }
        }
        dfs2(0, 0, grid[0][0]);
        while(vis.size() < n*n){
            mx = 0, mxid = 0;
            for (int color = 1; color <= 6; ++color) {
                cnt = 0;
                newvis[color].clear();
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        newvisited[color][j][k] = visited[j][k];
                    }
                }
                for (auto v : vis) {
                    for (int i = 0; i < 4; ++i) {
                        int newr = v.first+dirr[i], newc = v.second+dirc[i];
                        if(inrange(newr, newc) && !newvisited[color][newr][newc] && grid[newr][newc] == color){
                            dfs(newr, newc, color);
                        }
                    }
                }
                if(mx < cnt){
                    mx = cnt;
                    mxid = color;
                }
            }
            used[mxid]++;
            for (auto v: newvis[mxid]) {
                vis.push_back(v);
            }
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    visited[j][k] = newvisited[mxid][j][k];
                }
            }
        }
        int s = 0;
        for (int i = 1; i <= 6; ++i) {
            s += used[i];
        }
        cout << s << endl;
        for (int i = 1; i <= 6; ++i) {
            cout << used[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

