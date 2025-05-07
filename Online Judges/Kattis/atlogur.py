"""
https://open.kattis.com/problems/atlogur
Author: https://github.com/smh997/
"""

from math import ceil

n = int(input())
li = [list(map(int, input().split())) for _ in range(n)]
h, s = li[0][0], li[0][1]
ans = 0
for i in range(1, n):
    h2, s2 = li[i][0], li[i][1]
    t = ceil(h2 / s)
    if max(0, t-1) * s2 >= h:
        t2 = ceil(h / s2)
        h2 -= t2 * s
        h, s = h2, s2
        ans = i
    else:
        h -= max(0, t-1) * s2
print(ans+1)