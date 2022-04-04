"""
https://open.kattis.com/problems/expandingrods
Author: https://github.com/smh997/
"""
from decimal import Decimal
from math import asin
while True:
    L, n, C = map(Decimal, input().split())
    if L + n + C == -3:
        break
    two = Decimal(2)
    lo, hi = Decimal(0.0), L / two
    S = L + L * n * C
    while hi - lo > 1e-9:
        h = (hi + lo) / two
        R = h / two + L  * L / (8 * h)
        th = two * Decimal(asin(L / (2 * R)))
        if R * th > S:
            hi = h
        else:
            lo = h
    print('%.09f' % lo)