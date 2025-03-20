"""
https://open.kattis.com/problems/fallingsnow2
Author: https://github.com/smh997/
"""

n, m = map(int, input().split())
grid = []
snows = [0 for j in range(m)]
for i in range(n):
    grid = [ch for ch in input()]
    for j in range(m):
        snows[j] += 1 if grid[j] == 'S' else 0
for i in range(n):
    ans = []
    for j in range(m):
        ans.append('.' if snows[j] + i < n else 'S')
    print(''.join(ans))

