"""
https://open.kattis.com/problems/locustlocus
Author: https://github.com/smh997/
"""
from math import gcd
n = int(input())
li = []
for i in range(n):
    y, a, b = map(int, input().split())
    li.append(y + (a * b // gcd(a, b)))
li.sort()
print(li[0])