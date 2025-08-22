"""
Author https://github.com/smh997/
https://open.kattis.com/problems/lotsofliquid
"""

n = int(input())
b = sum([a * a * a for a in list(map(float, input().split()))])
print(b ** (1/3))
