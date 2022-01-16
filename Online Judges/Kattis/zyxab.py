"""
https://open.kattis.com/problems/zyxab
Author: https://github.com/smh997/
"""
def rep(s: str):
    for ch in s:
        if s.count(ch) > 1:
            return True
    return False


n = int(input())
li = [input() for i in range(n)]
li = [a for a in li if len(a) >= 5 and not rep(a)]
candid = []
mi = 1e9
for a in li:
    if len(a) < mi:
        candid = [a]
        mi = len(a)
    elif len(a) == mi:
        candid.append(a)
candid.sort()
print('neibb!' if not candid else candid[-1])
