"""
https://open.kattis.com/problems/cudoviste
Author: https://github.com/smh997/
"""
n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(input())
res = [0] * 5
for i in range(n-1):
    for j in range(m-1):
        li = [grid[i][j], grid[i+1][j], grid[i][j+1], grid[i+1][j+1]]
        if '#' not in li:
            res[li.count('X')] += 1
for i in range(5):
    print(res[i])