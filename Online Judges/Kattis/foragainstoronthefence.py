"""
Author https://github.com/smh997/
https://open.kattis.com/problems/foragainstoronthefence
"""

xp, yp = map(int, input().split())
xv, yv = map(int, input().split())
u = int(input())
d = (xp - xv) ** 2 + (yp - yv) ** 2
print('for' if d < u else 'against' if d > u else 'on the fence')
