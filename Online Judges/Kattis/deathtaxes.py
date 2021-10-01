"""
https://open.kattis.com/problems/deathtaxes
Author: https://github.com/smh997/
"""
from decimal import Decimal
share = 0
mid = 0

while True:
    s = input().split()
    if s[0] == 'die':
        y = int(s[1])
        y = Decimal(y)
        if y < mid:
            print('%7f' % (Decimal(share) * y))
        else:
            print('%7f' % (Decimal(share) * (Decimal(y - (y-mid) * Decimal(0.3)))))
        break
    if s[0] == 'buy':
        x, y = int(s[1]), int(s[2])
        mid = Decimal((share * mid + x * y)) / Decimal(share + x)
        share += x
    elif s[0] == 'sell':
        x, y = int(s[1]), int(s[2])
        share -= x
    elif s[0] == 'merge':
        x = int(s[1])
        mid = Decimal(x) * mid
        share //= x
    elif s[0] == 'split':
        x = int(s[1])
        mid = mid / Decimal(x)
        share *= x