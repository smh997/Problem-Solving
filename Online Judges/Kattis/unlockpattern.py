"""
https://open.kattis.com/problems/unlockpattern
Author: https://github.com/smh997/
"""

import math


def dis(b, c):
    return math.sqrt((b[0] - c[0])**2 + (b[1] - c[1])**2)


li = [(0, 0) for i in range(10)]
for i in range(3):
    a = list(map(int, input().split()))
    for j in range(3):
        li[a[j]] = (i, j)
res = 0
for i in range(2, 10):
    res += dis(li[i], li[i-1])
print(res)