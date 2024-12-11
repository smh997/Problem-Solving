"""
https://open.kattis.com/problems/goombastacks
Author: https://github.com/smh997/
"""

n, g = int(input()), 0
for i in range(n):
    gg, b = map(int, input().split())
    g += gg
    if g < b:
        print('impossible')
        exit(0)
print('possible')