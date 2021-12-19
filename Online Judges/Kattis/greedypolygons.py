"""
https://open.kattis.com/problems/greedypolygons
Author: https://github.com/smh997/
"""
from math import pi, tan
N = int(input())
for i in range(N):
    n, l, d, g = map(int, input().split())
    print((l * l * n) / (4 * tan(pi/n)) + n * l * g * d + (pi * ((g * d) ** 2)))
