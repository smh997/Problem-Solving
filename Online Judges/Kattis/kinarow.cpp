/*
 * https://open.kattis.com/problems/kinarow
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int X = 0, O = 0;
int m, n, k, L;
char grid[203][203];
int dirx[4] = {1, 1, 0, -1};
int diry[4] = {0, 1, 1, 1};

bool inrange(int i, int j, int dir){
    return 0 <= i + (k-1) * diry[dir] && i + (k-1) * diry[dir] < n && 0 <= j + (k-1) * dirx[dir] && j + (k-1) * dirx[dir] < m;
}

bool check(int i, int j, int dir){
    char ch = grid[i][j];
    for (int step = 1; step < k; ++step) 
        if(grid[i + step * diry[dir]][j + step * dirx[dir]] != ch)
            return false;
    return true;
}

int main()
{
    cin >> L;
    while(L--){
        cin >> m >> n >> k;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> grid[i][j];
        if (k > max(n,  m))
            continue;
        
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(grid[i][j] != '.'){
                    for (int d = 0; d < 4; ++d) {
                        if(inrange(i, j, d) && check(i, j, d)){
                            if(grid[i][j] == 'x'){
                                X++;                                
                            }
                            else
                                O++;
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }        
    }
    cout << X << ":" << O << endl;
    return 0;
}

