"""
https://open.kattis.com/problems/stockbroker
Author: https://github.com/smh997/
"""
from math import floor
money = 100
n = int(input())
pre = int(input())
for i in range(1, n):
    cur = int(input())
    if cur > pre:
        money += min(100000, floor(money / pre)) * (cur - pre)
    pre = cur
print(money)