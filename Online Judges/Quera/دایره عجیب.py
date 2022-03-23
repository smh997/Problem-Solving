"""
https://quera.org/problemset/34081/
Author: https://github.com/smh997/
"""
import math
n, k = map(int, input().split())
print(n * k // math.gcd(n, k) // k)