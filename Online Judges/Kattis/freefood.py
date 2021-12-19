"""
https://open.kattis.com/problems/freefood
Author: https://github.com/smh997/
"""
n = int(input())
ss = []
f1, f2, res = -1, -1, 0
for i in range(n):
    s, t = map(int, input().split())
    ss.append((s, t))
ss.sort()
for a in ss:
    if f1 == -1:
        f1 = a[0]
        f2 = a[1]
    elif f1 <= a[0] <= f2:
        if a[1] > f2:
            f2 = a[1]
    elif a[0] > f2:
        res += f2 - f1 + 1
        f1 = a[0]
        f2 = a[1]
res += f2 - f1 + 1
print(res)