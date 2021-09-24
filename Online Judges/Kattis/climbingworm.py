"""
https://open.kattis.com/problems/climbingworm
Author: https://github.com/smh997/
"""
a, b, h = map(int, input().split())
t = 1
cur = a
while cur < h:
    cur += a - b
    t += 1
print(t)