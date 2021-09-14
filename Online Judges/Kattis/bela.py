"""
https://open.kattis.com/problems/bela
Author: https://github.com/smh997/
"""
d = {'A': (11, 11), 'K': (4, 4), 'Q': (3, 3), 'J': (20, 2), 'T': (10, 10), '9': (14, 0), '8': (0, 0), '7': (0, 0)}
n, b = input().split()
n = int(n)
s = 0
for i in range(4 * n):
    a = input()
    s += d[a[0]][0] if a[1] == b else d[a[0]][1]
print(s)
