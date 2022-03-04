"""
https://quera.org/problemset/35254/
Author: https://github.com/smh997/
"""
import math
n = int(input())
st = input()
s, t = map(int, input().split())
h = max(s, t)
l = min(s, t)
res = 0
ss = 0
for i in range(l - 1, h):
    if st[i] == 'H':
        ss += 1
    elif ss == 0:
        continue
    elif math.log2(ss) == float(math.floor(math.log2(ss))):
        res += 1
        ss = 0
    else:
        while ss:
            ss -= 2 ** (math.floor(math.log2(ss)))
            res += 1
print(res)