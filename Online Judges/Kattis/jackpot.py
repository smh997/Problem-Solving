"""
https://open.kattis.com/problems/jackpot
Author: https://github.com/smh997/
"""
from math import gcd
billion = int(1e9)
n = int(input())
for i in range(n):
    w = int(input())
    li = list(map(int ,input().split()))
    lcm = 1
    for a in li:
        lcm = lcm * (a // gcd(lcm, a))
    print(lcm if lcm <= billion else 'More than a billion.')