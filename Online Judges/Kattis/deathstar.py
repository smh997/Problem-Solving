"""
https://open.kattis.com/problems/deathstar
Author: https://github.com/smh997/
"""
n = int(input())
res = []
for i in range(n):
    li = list(map(int, input().split()))
    a = 0
    for aj in li:
        a |= aj
    res.append(str(a))
print(' '.join(res))