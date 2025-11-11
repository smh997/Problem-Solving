/*
 * https://open.kattis.com/problems/nineknights
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

char grid[5][5];

int main() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> grid[i][j];
        }
    }
    int c = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(grid[i][j] == 'k') {
                c++;
                for(int di = -2; di <= 2; di++) {
                    for(int dj = -2; dj <= 2; dj++) {
                        if(abs(di) + abs(dj) == 3) {
                            int ni = i + di;
                            int nj = j + dj;
                            if(ni >= 0 && ni < 5 && nj >= 0 && nj < 5) {
                                if(grid[ni][nj] == 'k') {
                                    cout << "invalid" << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(c != 9) {
        cout << "invalid" << endl;
        return 0;
    }
    cout << "valid" << endl;
}
