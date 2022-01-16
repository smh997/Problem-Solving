"""
https://open.kattis.com/problems/zipline
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    w, g, h, r = map(int, input().split())
    if g == h == r:
        print(w, w)
        continue
    g -= r
    h -= r
    d = abs(g-h)
    print((d*d + w*w)**0.5, end=' ')
    x = (g/(g+h)) * w
    x2 = w - x
    print((x*x+g*g)**0.5 + (x2*x2+h*h)**0.5)
