/*
 * https://open.kattis.com/problems/terraces
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int grid[503][503];
bool visited[503][503];
int r, c;

int cnt = 0;
int collect_cnt;
int collect_res;

void collect(int i, int j){
    visited[i][j] = 1;
    collect_cnt++;
    if(i-1 >= 0){
        if(grid[i-1][j] < grid[i][j])
            collect_res = 0;
        if(grid[i-1][j] == grid[i][j] && !visited[i-1][j])
            collect(i-1, j);
    }
    if(i+1 < r){
        if(grid[i+1][j] < grid[i][j])
            collect_res = 0;
        if(grid[i+1][j] == grid[i][j] && !visited[i+1][j])
            collect(i+1, j);
    }
    if(j-1 >= 0){
        if(grid[i][j-1] < grid[i][j])
            collect_res = 0;
        if(grid[i][j-1] == grid[i][j] && !visited[i][j-1])
            collect(i, j-1);
    }
    if(j+1 < c){
        if(grid[i][j+1] < grid[i][j])
            collect_res = 0;
        if(grid[i][j+1] == grid[i][j] && !visited[i][j+1])
            collect(i, j+1);
    }
}


int main(){
    
    cin >> c >> r;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin >> grid[i][j];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            bool good = 1;
            if((i-1 >= 0 && grid[i-1][j] <= grid[i][j])
                    || (i+1 < r && grid[i+1][j] <= grid[i][j])
                    || (j-1 >= 0 && grid[i][j-1] <= grid[i][j])
                    || (j+1 < c && grid[i][j+1] <= grid[i][j]))
                good = 0;
            if(good)
                cnt++;
        }
    }
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            bool good = 0;
            if ((i-1 >= 0 && grid[i-1][j] == grid[i][j])
                    || (i+1 < r && grid[i+1][j] == grid[i][j])
                    || (j-1 >= 0 && grid[i][j-1] == grid[i][j])
                    || (j+1 < c && grid[i][j+1] == grid[i][j]))
                good = 1;
            if(good && !visited[i][j]){
                collect_cnt = 0;
                collect_res = 1;
                collect(i, j);
                if(collect_res)
                    cnt += collect_cnt;
            }
        }
    }
    cout << cnt << endl;

}
