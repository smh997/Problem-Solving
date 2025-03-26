"""
https://open.kattis.com/problems/dfyrirdreki
Author: https://github.com/smh997/
"""

a, b, c = int(input()), int(input()), int(input())
d = b * b - 4 * a * c
print(0 if d < 0 else 1 if d == 0 else 2)