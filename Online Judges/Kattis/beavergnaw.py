"""
https://open.kattis.com/problems/beavergnaw
Author: https://github.com/smh997/
"""
from math import pi
while True:
    d, v = map(int, input().split())
    if not d and not v:
        break
    print(2*(pow(((((pi * pow(d/2, 2) * d - v) - (pi * pow(d/2,2) * (d/3))) * 1.5) / (2 * pi)), (1.0/3))))