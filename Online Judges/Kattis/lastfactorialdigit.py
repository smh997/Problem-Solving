"""
https://open.kattis.com/problems/lastfactorialdigit
Author: https://github.com/smh997/
"""
from math import factorial
n = int(input())
for i in range(n):
    print(factorial(int(input()))%10)
