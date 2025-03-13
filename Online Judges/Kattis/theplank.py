"""
https://open.kattis.com/problems/theplank
Author: https://github.com/smh997/
"""

def track(j, n):
    if j == n:
        return 1
    if j > n:
        return 0
    s = 0
    for i in range(1, 4):
        s += track(j+i, n)
    return s
n = int(input())
print(track(0, n))