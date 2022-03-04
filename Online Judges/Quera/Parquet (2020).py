"""
https://quera.org/problemset/132252/
Author: https://github.com/smh997/
"""
b, y = map(int, input().split())
wpl = (b + 4) // 2
wl = y - 4 + 2 * wpl
x = (wpl ** 2 - 4 * wl) ** (0.5)
w1 = (-wpl + x) // (-2)
w2 = (-wpl - x) // (-2)
l1 = l2 = 0
if w1 > 0:
    l1 = wl // w1
    print(int(l1), int(w1))
else:
    l2 = wl // w2
    print(int(l2), int(w2))
