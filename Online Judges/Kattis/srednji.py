"""
https://open.kattis.com/problems/srednji
Author: https://github.com/smh997/
"""
from builtins import reversed

n, b = map(int, input().split())
li = list(map(int, input().split()))
it = 0
mp = dict()
res = 0
mp[0] = 1
for i in range(n):
    if li[i] == b:
        it = i
s = 0
for i in range(it+1, n):
    if li[i] > b:
        s += 1
    else:
        s -= 1
    if s not in mp:
        mp[s] = 0
    mp[s] += 1
s = 0
for i in reversed(range(it)):
    if li[i] > b:
        s += 1
    else:
        s -= 1
    if -s in mp:
        res += mp[-s]
print(res + mp[0])