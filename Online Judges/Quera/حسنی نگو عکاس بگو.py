"""
https://quera.org/problemset/34082/
Author: https://github.com/smh997/
"""
n, k = map(int, input().split())
li = list(map(int, input().split()))
c = 0
res = 1
for a in li:
    if c + a <= k:
        c += a
    else:
        c = a
        res += 1
print(res)