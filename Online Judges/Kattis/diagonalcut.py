"""
https://open.kattis.com/problems/diagonalcut
Author: https://github.com/smh997/
"""
import math
n, m = map(int, input().split())
g = math.gcd(m, n)
print(g if (n//g)%2 and (m//g)%2 else 0)