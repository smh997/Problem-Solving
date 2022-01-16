"""
https://open.kattis.com/problems/trollhunt
Author: https://github.com/smh997/
"""
b, k, g = map(int, input().split())
print((b - 1) // (k // g) if (b - 1) % (k // g) == 0 else (b - 1) // (k // g) + 1)
