/*
 * https://open.kattis.com/problems/islands3
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int r, c;
char grid[53][53];
bool visited[53][53];
int adjR[4]{1, -1, 0, 0}, adjC[4]{0, 0, 1, -1};

void dfs(int i, int j){
    if(i < 0 || i >= r || j < 0 || j >= c)
        return;
    if(visited[i][j])
        return;
    visited[i][j] = 1;
    if(grid[i][j] == 'W')
        return;
    for (int k = 0; k < 4; ++k) {
        dfs(i + adjR[k], j + adjC[k]);
    }
}

int main(){
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
            visited[i][j] = 0;
        }
    }
    int cc = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(!visited[i][j] && grid[i][j] == 'L'){
                dfs(i, j);
                cc++;
            }
        }
    }
    cout << cc << endl;
}

