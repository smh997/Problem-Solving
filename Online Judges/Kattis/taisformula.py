"""
https://open.kattis.com/problems/taisformula
Author: https://github.com/smh997/
"""
n = int(input())
lt, lv, res = 0, 0, 0
for i in range(n):
    t, v = map(str, input().split())
    t, v = int(t), float(v)
    if lv == 0 and lt == 0:
        lv, lt = v, t
        continue
    res += (v + lv) * (t - lt) / 2000
    lt, lv = t, v
print('%.6f' % res)