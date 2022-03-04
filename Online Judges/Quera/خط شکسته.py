"""
https://quera.org/problemset/64435/
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    res = 0
    n, m = map(int, input().split())
    grid = [[] for j in range(n)]
    for j in range(n):
        grid[j] = input()
    for j in range(m):
        for k in range(n):
            if grid[k][j] == '_':
                res += n - k - 1
                break
            elif grid[k][j] != '.':
                res += 0.5 + n - k - 1
                break
    print('%.3f' % res)