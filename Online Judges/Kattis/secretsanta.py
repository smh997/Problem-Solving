"""
https://open.kattis.com/problems/secretsanta
Author: https://github.com/smh997/
"""
from decimal import Decimal
n = int(input())
if n > 5000:
    n = 5000
if n == 1:
    print(1)
    exit(0)
elif n == 2:
    print(0.5000000)
    exit(0)
a = 0
b = 1
c = 0
ans = 0
for i in range(3, n+1):
    c = (i-1) * (b+a)
    a = b
    b = c
ans = Decimal(c)
for i in reversed(range(2, n+1)):
    ans = ans / Decimal(i)
print(1-ans)
