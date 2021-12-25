"""
https://open.kattis.com/problems/quickestimate
Author: https://github.com/smh997/
"""
from math import log10
n = int(input())
for i in range(n):
    inp = int(input())
    print(int(log10(inp)) + 1 if inp != 0 else 1)