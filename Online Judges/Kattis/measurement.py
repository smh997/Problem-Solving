"""
https://open.kattis.com/problems/measurement
Author: https://github.com/smh997/
"""
from decimal import Decimal
sc = {'thou': 7, 'th': 7, 'inch': 0, 'in': 0, 'foot': 1, 'ft': 1, 'yard': 2, 'yd': 2, 'chain': 3, 'ch': 3, 'furlong': 4, 'fur': 4, 'mile': 5, 'mi': 5, 'league': 6, 'lea': 6}
li = [1000, 12000, 36000, 792000, 7920000, 63360000, 190080000, 1]
v, u, inn, uu = map(str, input().split())
v = Decimal(v)
print('%.10f' % (Decimal(Decimal(li[sc[u]]) * v / Decimal(li[sc[uu]]))))