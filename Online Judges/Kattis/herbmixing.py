"""
https://open.kattis.com/problems/herbmixing
Author: https://github.com/smh997/
"""

def calc(g, r):
    if not g:
        return 0
    if r:
        val = min(r, g)
        return val * 10 + calc(g-val, r-val)
    elif g >= 3:
        return 10 + calc(g-3, r)
    elif g >= 2:
        return 3 + calc(g-2, r)
    else:
        return 1 + calc(g-1, r)

g, r = map(int, input().split())
print(calc(g, r))