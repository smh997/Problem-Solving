"""
https://open.kattis.com/problems/eventplanning
Author: https://github.com/smh997/
"""
n, b, h, w = map(int, input().split())
res = b + 10
for i in range(h):
    p = int(input())
    weeks = list(map(int, input().split()))
    for i in range(w):
        if weeks[i] >= n and n * p <= b:
            res = min(res, n * p)
print(res if res <= b else 'stay home')