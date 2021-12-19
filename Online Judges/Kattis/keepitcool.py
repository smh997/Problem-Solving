"""
https://open.kattis.com/problems/keepitcool
Author: https://github.com/smh997/
"""
n, m, s, d = map(int, input().split())
li2 = list(map(int, input().split()))
li = sorted([(li2[i], i) for i in range(s)])
flag = [True] * s
res = [0] * s
for i in range(s):
    if li[i][0] < d:
        res[li[i][1]] = min(d - li[i][0], n)
        n -= min(d-li[i][0], n)
        flag[li[i][1]] = False
    if not n:
        break
for i in range(s):
    if flag[i]:
        if li2[i]:
            m -= min(m, li2[i])
    if not m:
        break

if m:
    print('impossible')
else:
    print(' '.join([str(a) for a in res]))
