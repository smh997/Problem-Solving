"""
https://open.kattis.com/problems/conteststruggles
Author: https://github.com/smh997/
"""
n, k = map(int, input().split())
d, s = map(int, input().split())
print((n * d - k * s) / (n-k) if 0 <= (n * d - k * s) / (n-k) <= 100 else 'impossible')
