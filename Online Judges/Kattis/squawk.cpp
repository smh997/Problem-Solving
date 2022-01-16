/*
 * https://open.kattis.com/problems/squawk
 * Author: https://github.com/smh997/
 */

#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100

int n, m, s, t;

struct Matrix {
    long long int mat[MAX_N][MAX_N];
}; // we will return a 2D array
Matrix matMul(Matrix a, Matrix b) { // O(n^3)
    Matrix ans; int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (ans.mat[i][j] = k = 0; k < n; k++) // if necessary, use
                ans.mat[i][j] = (ans.mat[i][j] + ((a.mat[i][k]) * (b.mat[k][j]))); // modulo arithmetic
    return ans;
}
Matrix matPow(Matrix base, long long int p) { // O(n^3 log p)
    Matrix ans; int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            ans.mat[i][j] = (i == j); // prepare identity matrix
    while (p) { // iterative version of Divide & Conquer exponentiation
        if (p & 1) ans = matMul(ans, base); // if p is odd (last bit is on)
        base = matMul(base, base); // square the base
        p >>= 1; // divide p by 2
    }
    return ans;
}

int a, b;

int main(){
    cin  >> n >> m >> s >> t;
    Matrix ans, res;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        ans.mat[a][b] = ans.mat[b][a] = 1;
    }
    res = matPow(ans, t);
    long long int resum = 0;
    for (int i = 0; i < n; ++i) {
        resum += res.mat[s][i];
    }
    cout << resum << endl;
    return 0;
}
