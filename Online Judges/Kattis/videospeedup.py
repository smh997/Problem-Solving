"""
https://open.kattis.com/problems/videospeedup
Author: https://github.com/smh997/
"""
n, p, k = map(int, input().split())
ti = list(map(int, input().split()))
last = 0
res = 0
v = 100
for i in range(n):
    res += (ti[i]-last) * v / 100
    last = ti[i]
    v += p
res += (k - last) * v / 100
print('%.6f' % res)