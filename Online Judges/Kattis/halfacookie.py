"""
https://open.kattis.com/problems/halfacookie
Author: https://github.com/smh997/
"""
from math import acos, pi
import sys

lines = sys.stdin.readlines()
for line in lines:
    r, x, y = map(float, line.split())
    a = (x * x + y * y) ** 0.5
    if a >= r:
        print('miss')
        continue
    m = (acos(a / r) * r * r) - (a * ((r * r - a * a) ** 0.5))
    mm = pi * r * r - m
    print(mm, m)
