"""
https://open.kattis.com/problems/eveningout1
Author: https://github.com/smh997/
"""

a, b = map(int, input().split())
print(0 if a % b == 0 else min(b - (a % b), a % b))