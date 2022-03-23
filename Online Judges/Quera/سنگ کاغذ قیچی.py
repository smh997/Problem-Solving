"""
https://quera.org/problemset/18213/
Author: https://github.com/smh997/
"""
p, r, s, a, b, c = map(int, input().split())
res = 0
if p <= c:
    res += p
    c -= p
    p = 0
else:
    res += c
    p -= c
    c = 0
if r <= a:
    res += r
    a -= r
    r = 0
else:
    res += a
    r -= a
    a = 0
if s <= b:
    res += s
    b -= s
    s = 0
else:
    res += b
    s -= b
    b = 0
if p <= a:
    a -= p
    p = 0
else:
    p -= a
    a = 0
if r <= b:
    b -= r
    r = 0
else:
    r -= b
    b = 0
if s <= c:
    c -= s
    s = 0
else:
    s -= c
    c = 0
res -= (a + b + c)
print(res)