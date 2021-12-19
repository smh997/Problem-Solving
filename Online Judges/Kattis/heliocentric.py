"""
https://open.kattis.com/problems/heliocentric
Author: https://github.com/smh997/
"""
import sys
i = 0
lines = sys.stdin.readlines()
for line in lines:
    i += 1
    e, m = map(int, line.split())
    if e == m == 0:
        print('Case %d: %d' % (i, 0))
        continue
    if 365 - e == 687 - m:
        print('Case %d: %d' % (i, 365 - e))
        continue
    pree = e
    e += 687 - m
    while e % 365:
        e += 687
    print('Case %d: %d' % (i, e-pree))

