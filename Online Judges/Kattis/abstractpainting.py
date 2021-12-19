"""
https://open.kattis.com/problems/abstractpainting
Author: https://github.com/smh997/
"""
t = int(input())
mod = 1e9 + 7
while t:
    r, c = map(int, input().split())
    res = 1
    for i in range(r):
        for j in range(c):
            res = res * (2 if i and j else (6 if i or j else 18)) % mod
    print(int(res))
    t -= 1
