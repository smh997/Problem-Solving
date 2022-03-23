"""
https://quera.org/problemset/33023/
Author: https://github.com/smh997/
"""
from math import inf
n, m = map(int, input().split())
mat = [[0 for j in range(m)] for i in range(n)]
for i in range(n):
    mat[i] = list(map(int, input().split()))
z = 0
for i in range(1, n - 1):
    for j in range(1, m - 1):
        if (mat[i][j - 1] < mat[i][j] < mat[i - 1][j] and mat[i][j + 1] < mat[i][j] < mat[i + 1][j]) or (mat[i - 1][j] < mat[i][j] < mat[i][j - 1] and mat[i + 1][j] < mat[i][j] < mat[i][j + 1]):
            z += 1
print(z)
