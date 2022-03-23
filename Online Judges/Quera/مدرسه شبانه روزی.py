"""
https://quera.org/problemset/61038/
Author: https://github.com/smh997/
"""
import math
n = int(input())
a = int(input())
li = [a]
k = a
for i in range(1, n):
    li.append(int(input()))
    a = math.gcd(k, li[i])
    k = k * li[i] // a
print(k % 30 + 1)
