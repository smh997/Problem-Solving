"""
https://open.kattis.com/problems/artichoke
Author: https://github.com/smh997/
"""
from math import sin, cos
p, a, b, c, d, n = map(int, input().split())
if n == 1:
    print(0)
    exit(0)
pr = [p*(sin(a*i+b)+cos(c*i+d)+2) for i in range(n+1)]
maxv = pr[1]
maxd = 0
for i in range(2, n+1):
    maxd = max(maxd, maxv - pr[i])
    maxv = max(maxv, pr[i])
print('%.7f' % maxd)
