"""
https://open.kattis.com/problems/jughard
Author: https://github.com/smh997/
"""
from math import gcd
n = int(input())
for i in range(n):
    a, b, c = map(int, input().split())
    print('No' if c > max(a, b) or c % gcd(a, b) else 'Yes')