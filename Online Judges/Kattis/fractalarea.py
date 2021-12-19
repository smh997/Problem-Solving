"""
https://open.kattis.com/problems/fractalarea
Author: https://github.com/smh997/
"""
from math import pi
t = int(input())
for i in range(t):
    r, n = map(int, input().split())
    if n == 1:
        print(pi*r*r)
    elif n == 2:
        print(2*pi*r*r)
    else:
        res = 2*pi*r*r
        r /= 4
        a = 4
        for j in range(3, n+1):
            res += 3*a*pi*r*r
            r /= 2
            a *= 3
        print(res)
