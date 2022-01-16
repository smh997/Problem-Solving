"""
https://open.kattis.com/problems/smallestmultiple
Author: https://github.com/smh997/
"""
import math, sys

lines = sys.stdin.readlines()
for line in lines:
    li = list(map(int, line.split()))
    n = len(li)
    if n == 1:
        print(li[0])
        continue
    lc = li[0]
    for i in range(1, n):
        g = math.gcd(li[i], lc)
        lc = lc * (li[i] // g)
    print(lc)