/*
 * https://open.kattis.com/problems/amoebas
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int r, c;
char g[103][103];
int adjR[8]{0, 0, -1, 1, -1, 1, -1, 1};
int adjC[8]{-1, 1, 0, 0, -1, -1, 1, 1};
bool vis[103][103];

void dfs(int i, int j){
    vis[i][j] = 1;
    for(int k = 0; k < 8; k++){
        int ni = i + adjR[k], nj = j + adjC[k];
        if(ni >= 0 && ni < r && nj >= 0 && nj < c && !vis[ni][nj] && g[ni][nj] == '#')
            dfs(ni, nj);
    }
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> g[i][j];
    int ans = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(!vis[i][j] && g[i][j] == '#'){
                ans++;
                dfs(i, j);
            }
    cout << ans << endl;
}