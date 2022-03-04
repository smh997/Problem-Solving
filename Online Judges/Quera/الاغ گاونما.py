"""
https://quera.org/problemset/72878/
Author: https://github.com/smh997/
"""
t, a, b = map(int, input().split())
ar = ma = t // (a + b + 2)
rem = t % (a + b + 2)
if 1 <= rem:
    ar += 1
if a + 1 <= rem:
    ma += 1
print(ar, ma)