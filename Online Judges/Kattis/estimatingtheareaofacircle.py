"""
https://open.kattis.com/problems/estimatingtheareaofacircle
Author: https://github.com/smh997/
"""
from math import pi
while True:
    r, m, c = map(float, input().split())
    if not (r or m or c):
        break
    print(pi*r*r, (4*r*r)*(c/m))