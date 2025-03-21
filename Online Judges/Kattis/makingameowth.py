"""
https://open.kattis.com/problems/makingameowth
Author: https://github.com/smh997/
"""

n, p, x, y = map(int, input().split())
print((p // (n-1)) * y + p * x)