"""
https://open.kattis.com/problems/thanos
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    p, r, f = map(int, input().split())
    res = 0
    while p <= f:
        res += 1
        p *= r
    print(res)