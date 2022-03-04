/*
 * https://quera.org/problemset/82383/
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, m;
int A[203][203];
int Asum[203][203];
int H[203][203];
int V[203][203];
int dist[203][203];
int dist2[203][203];

int dirr[2][2] = {{0, 1}, {0, -1}};
int dirc[2][2] = {{1, 0}, {-1, 0}};

bool inrange(int i, int j){
    return i >= 0 && j >= 0 && i <= n && j <= m;
}


int main(){
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> A[i][j];
    for (int i = 0; i < n+1; ++i)
        for (int j = 0; j < m; ++j)
            cin >> H[i][j], H[i][j] = -H[i][j];
    for (int i = 0; i < m+1; ++i)
        for (int j = 0; j < n; ++j)
            cin >> V[j][i], V[j][i] = - V[j][i];
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= 0; --j) {
            Asum[i][j] = ((j == m) ? 0 : Asum[i][j+1]) + A[i][j];
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if(i == j && i == 0){
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = max((inrange(i-1, j) ? dist[i-1][j] + V[i-1][j] + Asum[i-1][j] : INT_MIN), (inrange(i, j-1) ? dist[i][j-1] + H[i][j-1] : INT_MIN));
        }
    }
    for (int i = n; i >= 0; --i) {
        for (int j = m; j >= 0; --j) {
            if(i == n && j == m){
                dist2[i][j] = 0;
                continue;
            }
            dist2[i][j] = max((inrange(i+1, j) ? dist2[i+1][j] + V[i][j] - Asum[i][j] : INT_MIN), (inrange(i, j+1) ? dist2[i][j+1] + H[i][j] : INT_MIN));
        }
    }
    cout << dist[n][m] + dist2[0][0] << endl;
    return 0;
}
