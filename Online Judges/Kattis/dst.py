"""
https://open.kattis.com/problems/dst
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    ch, d, h, m = map(str, input().split())
    d, h, m = int(d), int(h), int(m)
    if ch == 'F':
        h = (h + (d // 60)) % 24
        rem = d % 60
        if m + rem >= 60:
            h = (h + 1) % 24
        m = (m + rem) % 60
    else:
        h = ((h - (d // 60)) + 24) % 24
        rem = d % 60
        if m - rem < 0:
            h = (h + 23) % 24
        m = (m - rem + 60) % 60
    print(h, m)
