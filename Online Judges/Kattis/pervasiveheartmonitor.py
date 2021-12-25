"""
https://open.kattis.com/problems/pervasiveheartmonitor
Author: https://github.com/smh997/
"""
from decimal import Decimal
import sys
lines = sys.stdin.readlines()
for line in lines:
    li = line.split()
    name = []
    res = Decimal(0)
    if li[0].isalpha():
        it = 0
        while li[it].isalpha():
            name.append(li[it])
            it += 1
        for i in range(it, len(li)):
            res += Decimal(li[i])
        print('%.3f' % (res / Decimal(len(li) - it)), end=' ')
        print(' '.join(name))
    else:
        it = 0
        while not li[it].isalpha():
            res += Decimal(li[it])
            it += 1
        for i in range(it, len(li)):
            name.append(li[i])
        print('%.3f' % (res / Decimal(it)), end=' ')
        print(' '.join(name))
