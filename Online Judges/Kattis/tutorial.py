"""
https://open.kattis.com/problems/tutorial
Author: https://github.com/smh997/
"""
from math import log2
m, n, t = map(int, input().split())
if t == 1:
    res = 1
    for i in reversed(range(1, n+1)):
        res *= i
        if res > m:
            print('TLE')
            exit(0)
    print('AC')
elif t == 2:
    res = 1
    for i in range(n):
        res *= 2
        if res > m:
            print('TLE')
            exit(0)
    print('AC')
elif t == 3:
    res = 1
    for i in range(4):
        res *= n
        if res > m:
            print('TLE')
            exit(0)
    print('AC')
elif t == 4:
    res = 1
    for i in range(3):
        res *= n
        if res > m:
            print('TLE')
            exit(0)
    print('AC')
elif t == 5:
    res = 1
    for i in range(2):
        res *= n
        if res > m:
            print('TLE')
            exit(0)
    print('AC')
elif t == 6:
    res = n * log2(n)
    if res > m:
        print('TLE')
    else:
        print('AC')
else:
    res = n
    if res > m:
        print('TLE')
    else:
        print('AC')