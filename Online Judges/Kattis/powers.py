"""
https://open.kattis.com/problems/powers
Author: https://github.com/smh997/
"""
a, b = map(int, input().split())
if a % 2:
    print(0)
else:
    print(pow(a // 2, b, a))
