"""
https://open.kattis.com/problems/semafori
Author: https://github.com/smh997/
"""
n, l = map(int, input().split())
t, dis = 0, 0
for i in range(n):
    d, r, g = map(int, input().split())
    t += d - dis
    dis = d
    if t % (r+g) < r:
        t += r - (t % (r+g))
print(t + (l-dis))