"""
https://open.kattis.com/problems/minesweeper
Author: https://github.com/smh997/
"""

n, m, k = map(int, input().split())
li = []
for i in range(n):
    li.append([])
    for _ in range(m):
        li[i].append('.')
for i in range(k):
    y, x = map(int, input().split())
    li[y-1][x-1] = '*'
for i in range(n):
    print(''.join(li[i]))
