"""
https://quera.org/problemset/102261/
Author: https://github.com/smh997/
"""
from math import floor, ceil
n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    print(floor(b ** 0.5) - ceil(a ** 0.5) + 1)
