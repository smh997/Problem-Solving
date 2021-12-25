"""
https://open.kattis.com/problems/mosquito
Author: https://github.com/smh997/
"""
import sys

lines = sys.stdin.readlines()
for line in lines:
    m, p, l, e, r, s, n = map(int, line.split())
    for i in range(n):
        nextl = m * e
        nextp = l // r
        nextm = p // s
        m = nextm
        p = nextp
        l = nextl
    print(m)
