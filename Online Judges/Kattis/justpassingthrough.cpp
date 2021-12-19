/*
 * https://open.kattis.com/problems/justpassingthrough
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num inf = LLONG_MAX;

int r, c, n;
num g[503][503];
bool p[503][503];

int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, -1, 1};

int adjRR[3]{0, -1, 1};
int adjCC[3]{1, 1, 1};

num dis[503][503][13];
priority_queue<pair<num, pair<int, pair<int, int>>>, vector<pair<num, pair<int, pair<int, int>>>>, greater<pair<num, pair<int, pair<int, int>>>>> dij;

int main(){
    cin >> r >> c >> n;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> g[i][j];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(g[i][j] != -1){
                bool pass = true;
                for(int k = 0; k < 2; k++){
                    int x = i + adjR[k], y = j + adjC[k];
                    if(!(x >= 0 && x < r && y >= 0 && y < c && g[x][y] != -1 && g[x][y] > g[i][j]))
                        pass = false;
                }
                for(int k = 2; k < 4; k++){
                    int x = i + adjR[k], y = j + adjC[k];
                    if(!(x >= 0 && x < r && y >= 0 && y < c && g[x][y] != -1 && g[x][y] < g[i][j]))
                        pass = false;
                }
                p[i][j] = pass;
            }
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            for(int k = 0; k <= n; k++)
                dis[i][j][k] = inf;
    for(int i = 0; i < r; i++)
        if(g[i][0] != -1)
            dis[i][0][0] = g[i][0], dij.push({g[i][0], {p[i][0], {i, 0}}});
    num ans = inf;
    while(!dij.empty()){
        auto state = dij.top();
        dij.pop();
        num w = state.first;
        int np = state.second.first;
        int i = state.second.second.first;
        int j = state.second.second.second;
        if(dis[i][j][np] < w)
            continue;
        if(j == c - 1){
            if(np == n)
                ans = min(ans, w);
            continue;
        }
        for(int k = 0; k < 3; k++){
            int x = i + adjRR[k], y = j + adjCC[k];
            if(x >= 0 && x < r && y >= 0 && y < c && g[x][y] != -1 && np + p[x][y] <= n && w + g[x][y] < dis[x][y][np + p[x][y]])
                dis[x][y][np + p[x][y]] = w + g[x][y], dij.push({w + g[x][y], {np + p[x][y], {x, y}}});
        }
    }
    if(ans == inf)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
}