"""
https://open.kattis.com/problems/alehouse
Author: https://github.com/smh997/
"""
li = []
n, k = map(int, input().split())
for i in range(n):
    a, b = map(int, input().split())
    li.append((a, 1))
    li.append((b+k+1, -1))
c = 0
res = 0
for e in sorted(li):
    c += e[1]
    res = max(res, c)
print(res)