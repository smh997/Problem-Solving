"""
https://open.kattis.com/problems/hornrett
Author: https://github.com/smh997/
"""

a, b, c = map(int, input().split())
print(a * b // 2 if a * a + b * b == c * c else -1)
