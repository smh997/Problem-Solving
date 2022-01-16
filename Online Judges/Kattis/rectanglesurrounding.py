"""
https://open.kattis.com/problems/rectanglesurrounding
Author: https://github.com/smh997/
"""
while True:
    n = int(input())
    if not n:
        break
    grid = [[False for i in range(501)] for j in range(501)]
    for i in range(n):
        a, b, c, d = map(int, input().split())
        for j in range(a, c):
            for k in range(b, d):
                grid[j][k] = True
    res = 0
    for i in range(501):
        for j in range(501):
            if grid[i][j]:
                res += 1
    print(res)