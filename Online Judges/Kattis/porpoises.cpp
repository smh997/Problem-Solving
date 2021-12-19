/*
 * https://open.kattis.com/problems/porpoises
 * Author: https://github.com/smh997/
 */

#include<bits/stdc++.h>
using namespace std;

#define MAX_N 2 // Fibonacci matrix, increase/decrease this value as needed
#define mod 1000000000
struct Matrix {
    long long int mat[MAX_N][MAX_N];
}; // we will return a 2D array
Matrix matMul(Matrix a, Matrix b) { // O(n^3)
    Matrix ans; int i, j, k;
    for (i = 0; i < MAX_N; i++)
        for (j = 0; j < MAX_N; j++)
            for (ans.mat[i][j] = k = 0; k < MAX_N; k++) // if necessary, use
                ans.mat[i][j] = (ans.mat[i][j] + ((a.mat[i][k] % mod) * (b.mat[k][j] % mod))) % mod; // modulo arithmetic
    return ans;
}
Matrix matPow(Matrix base, long long int p) { // O(n^3 log p)
    Matrix ans; int i, j;
    for (i = 0; i < MAX_N; i++)
        for (j = 0; j < MAX_N; j++)
            ans.mat[i][j] = (i == j); // prepare identity matrix
    while (p) { // iterative version of Divide & Conquer exponentiation
        if (p & 1) ans = matMul(ans, base); // if p is odd (last bit is on)
        base = matMul(base, base); // square the base
        p >>= 1; // divide p by 2
    }
    return ans;
}

long long int p, k, y;
Matrix fib;
int main(){
    cin >> p;
    while(p--){
        cin >> k >> y;
        fib.mat[0][0] = fib.mat[0][1] = fib.mat[1][0] = 1;
        cout << k << " " << matPow(fib, y).mat[0][1] << endl;
    }
    return 0;
}
