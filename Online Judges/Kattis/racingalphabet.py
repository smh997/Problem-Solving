"""
https://open.kattis.com/problems/racingalphabet
Author: https://github.com/smh997/
"""
from math import pi
step = pi * 60 / 28
n = int(input())
di = {}
for i in range(26):
    di[chr(ord('A')+i)] = i
di['\''] = 27
di[' '] = 26
for i in range(n):
    inp = input()
    s = 0
    for j in range(1, len(inp)):
        dis = abs(di[inp[j]] - di[inp[j-1]])
        # print(inp[j-1], inp[j], di[inp[j-1]], di[inp[j]], dis, min(dis, 28 - dis))
        s += min(dis, 28 - dis)
    print((s * step)/15 + len(inp))
