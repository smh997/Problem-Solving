"""
https://quera.org/problemset/3411/
Author: https://github.com/smh997/
"""
n = int(input())
p = 1
for i in range(1, n + 1):
    p *= i
    while p % 10 == 0:
        p //= 10
    p %= 10000
print(p % 10)
