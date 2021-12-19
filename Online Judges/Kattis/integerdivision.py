"""
https://open.kattis.com/problems/integerdivision
Author: https://github.com/smh997/
"""
n, d = map(int, input().split())
li = list(map(int, input().split()))
res = {}
for i in range(len(li)):
    r = li[i] // d
    if r not in res:
        res[r] = 1
    else:
        res[r] += 1
s = 0
for k in res:
    s += res[k] * (res[k] - 1) // 2
print(s)