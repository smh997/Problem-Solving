"""
https://open.kattis.com/problems/prozor
Author: https://github.com/smh997/
"""
r, c, k = map(int, input().split())
li = []
for i in range(r):
    li.append([ch for ch in input()])
mx = 0
sx, sy = 0, 0
for i in range(r-k+1):
    for j in range(c-k+1):
        sm = 0
        for f in range(i + 1, i + k - 1):
            sm += li[f][j+1:j+k-1].count('*')
        if sm > mx:
            mx, sx, sy = sm, i, j
print(mx)
li[sx][sy], li[sx+k-1][sy], li[sx][sy+k-1], li[sx+k-1][sy+k-1] = '+', '+', '+', '+'
for i in range(sx+1, sx+k-1):
    li[i][sy], li[i][sy+k-1] = '|', '|'
for i in range(sy + 1, sy + k - 1):
    li[sx][i], li[sx+k-1][i] = '-', '-'
for i in range(r):
    print(''.join(li[i]))
