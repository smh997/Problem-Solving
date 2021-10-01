/*
 * https://open.kattis.com/problems/escapewallmaria
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 103

char grid[MAX_N][MAX_N];
int t, n, m;
int dist[MAX_N][MAX_N];
queue<pair<int, int>> q;
int dirr[4] = {0, 1, 0, -1};
int dirc[4] = {1, 0, -1, 0};
char mp[4] = {'L', 'U', 'R', 'D'};
bool inrange(int i, int j){
    return i >= 0 && i < n && j < m && j >= 0;
}

int main()
{
    cin >> t >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            cin >> grid[i][j], dist[i][j] = INT_MAX;
            if(grid[i][j] == 'S')
                q.push({i, j}), dist[i][j] = 0;
        }
    pair<int, int> p;
    int d, r, c, adjr, adjc;
    while(!q.empty()){
        p = q.front();
        q.pop();
        r = p.first;
        c = p.second;
        d = dist[r][c];
        if(r == 0 || r == n-1 || c == 0 || c == m-1){
            if(d <= t)
                cout << d << endl;
            else
                cout << "NOT POSSIBLE" << endl;
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            adjr = r + dirr[i], adjc = c + dirc[i];
            if(inrange(adjr, adjc))
                if(grid[adjr][adjc] == '0' || mp[i] == grid[adjr][adjc])
                    if(dist[adjr][adjc] > d + 1){
                        q.push({adjr, adjc});
                        dist[adjr][adjc] = d + 1;
                    }
        }
    }
    cout << "NOT POSSIBLE" << endl;
    return 0;
}

