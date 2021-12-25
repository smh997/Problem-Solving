"""
https://open.kattis.com/problems/namethatpermutation
Author: https://github.com/smh997/
"""
import sys

fact = [1, 1, 2, 6]
for i in range(4, 51):
    fact.append(fact[i-1] * i)

lines = sys.stdin.readlines()
for line in lines:
    n, k = map(int, line.split())
    li = [i + 1 for i in range(n)]
    res = []
    while len(li):
        f = k // fact[len(li) - 1]
        res.append(li[f])
        k = k % fact[len(li) - 1]
        li.pop(f)
    print(' '.join([str(a) for a in res]))