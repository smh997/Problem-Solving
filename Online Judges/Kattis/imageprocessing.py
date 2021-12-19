"""
https://open.kattis.com/problems/imageprocessing
Author: https://github.com/smh997/
"""
h, w, n, m = map(int, input().split())
mat1 = []
mat2 = []
for i in range(h):
    mat1.append(list(map(int, input().split())))
for i in range(n):
    tmp = list(map(int, input().split()))
    tmp.reverse()
    mat2.append(tmp)
mat2.reverse()
res = [[0 for i in range(w-m+1)] for j in range(h-n+1)]
for i in range(h-n+1):
    for j in range(w-m+1):
        for k in range(i, i+n):
            for l in range(j, j+m):
                res[i][j] += mat1[k][l] * mat2[k-i][l-j]
for i in range(h-n+1):
    for j in range(w-m+1):
        print(res[i][j], end='')
        print('\n' if j == w-m else ' ', end='')
