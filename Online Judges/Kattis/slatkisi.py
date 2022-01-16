"""
https://open.kattis.com/problems/slatkisi
Author: https://github.com/smh997/
"""
c, k = map(int, input().split())
print(round(c/(10**k))*(10**k))
