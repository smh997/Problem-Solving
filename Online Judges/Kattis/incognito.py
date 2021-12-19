"""
https://open.kattis.com/problems/incognito
Author: https://github.com/smh997/
"""
di = {}
t = int(input())
for i in range(t):
    di.clear()
    n = int(input())
    for j in range(n):
        _, k = map(str, input().split())
        di[k] = di[k]+1 if k in di else 2
    res = 1
    for v in di.values():
        res *= v
    print(res-1)
