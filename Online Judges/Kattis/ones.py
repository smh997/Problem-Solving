"""
https://open.kattis.com/problems/ones
Author: https://github.com/smh997/
"""
import sys

lines = sys.stdin.readlines()
for line in lines:
    n = int(line)
    res = 1
    a = 1
    while a % n:
        a = a * 10 + 1
        a %= n
        res += 1
    print(res)