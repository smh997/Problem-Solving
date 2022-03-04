/*
 * https://quera.org/problemset/3407/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    int m,n;
    int k;
    int x, y;
    cin >> m >> n >> k;
    char mat[m + 2][n + 2];
    for (int i = 0; i < m + 2; ++i) {
        for (int j = 0; j < n + 2; ++j) {
            mat[i][j] = '0';
        }
    }
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        mat[x][y] = '*';
    }
    for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if(mat[i][j] != '*'){
                for(int p = -1; p < 2; p++){
                    for(int q = -1; q < 2; q++){
                        if(mat[i + p][j + q] == '*'){
                            mat[i][j]++;
                        }
                    }
                }
            }
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

