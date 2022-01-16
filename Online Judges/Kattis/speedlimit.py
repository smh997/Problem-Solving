"""
https://open.kattis.com/problems/speedlimit
Author: https://github.com/smh997/
"""
while True:
    n = int(input())
    if n == -1:
        break
    res = 0
    tt = 0
    for i in range(n):
        s, t = map(int, input().split())
        res += (t - tt) * s
        tt = t
    print(res, 'miles')
