"""
https://open.kattis.com/problems/rationalsequence2
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    k, m = map(str, input().split())
    a, b = map(int, m.split('/'))
    su = 1
    r = 0
    while (a, b) != (1, 1):
        if a > b:
            a -= b
            r += su
        elif a < b:
            b -= a
        su *= 2
    print(k, su + r)