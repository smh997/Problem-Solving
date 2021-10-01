"""
https://open.kattis.com/problems/euclideantsp
Author: https://github.com/smh997/
"""
import math
from decimal import Decimal


def f(c):
    global n, p, s, v
    f1 = n * (Decimal(math.log2(n)) ** (Decimal(c * (2**0.5)))) / (p * 1000000000)
    f2 = s * Decimal(1+1/c) / v
    return f1 + f2


n, p, s, v = map(Decimal, input().split())
lo = 0.001
hi = 1000.0
while math.fabs(hi-lo) > 0.00000001:
    m1 = lo + (hi - lo)/3
    m2 = lo + 2 * (hi - lo)/3
    res1 = f(m1)
    res2 = f(m2)
    if res1 <= res2:
        hi = m2
    else:
        lo = m1
print(f(lo), lo)