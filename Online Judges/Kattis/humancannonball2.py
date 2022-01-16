"""
https://open.kattis.com/problems/humancannonball2
Author: https://github.com/smh997/
"""
import math as mh
n = int(input())
for i in range(n):
    v, teta, x, h1, h2 = map(float, input().split())
    t = x / (v * mh.cos(mh.radians(teta)))
    y = v * t * mh.sin(mh.radians(teta)) - 0.5 * 9.81 * t * t
    if h1 + 1 <= y <= h2 - 1:
        print('Safe')
    else:
        print('Not Safe')