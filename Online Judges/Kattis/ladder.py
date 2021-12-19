"""
https://open.kattis.com/problems/ladder
Author: https://github.com/smh997/
"""
from math import sin, radians, ceil
h, v = map(int, input().split())
print(ceil(h/sin(radians(v)))) 