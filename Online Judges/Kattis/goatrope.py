"""
https://open.kattis.com/problems/goatrope
Author: https://github.com/smh997/
"""
gx, gy, x1, y1, x2, y2 = map(int, input().split())
if gx < x1:
    if gy < y1:
        print(((x1-gx)**2 + (y1-gy)**2)**0.5)
    elif y1 <= gy <= y2:
        print(x1-gx)
    else:
        print(((x1 - gx) ** 2 + (gy - y2) ** 2) ** 0.5)
elif x1 <= gx <= x2:
    if gy < y1:
        print(y1-gy)
    else:
        print(gy-y2)
else:
    if gy < y1:
        print(((gx-x2)**2 + (y1-gy)**2)**0.5)
    elif y1 <= gy <= y2:
        print(gx-x2)
    else:
        print(((gx-x2)**2 + (gy-y2)**2)**0.5)
