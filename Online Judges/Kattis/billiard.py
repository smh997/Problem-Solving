"""
https://open.kattis.com/problems/billiard
Author: https://github.com/smh997/
"""
from math import pi, atan
while True:
    a, b, s, m, n = map(int, input().split())
    if (a, b, s, m, n) == (0, 0, 0, 0, 0):
        break
    print('%.2f' % (atan((b * n) / (a * m)) / pi * 180), end=' ')
    print('%.2f' % ((((b * n / 2)**2)+((a * m / 2)**2))**0.5 * 2 / s))
