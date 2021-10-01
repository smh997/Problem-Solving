"""
https://open.kattis.com/problems/expeditiouscubing
Author: https://github.com/smh997/
"""
from decimal import Decimal
t = list(map(Decimal, input().split()))
t.sort()
targ = Decimal(input())

if (t[1] + t[2] + t[3])/3 <= targ:
    print('infinite')
elif (t[0] + t[1] + t[2])/3 > targ:
    print('impossible')
else:
    print('%.2f' % (3*targ - (t[1] + t[2])))
