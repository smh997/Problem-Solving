"""
https://open.kattis.com/problems/kinahvisl
Author: https://github.com/smh997/
"""

a, b = input(), input()
print(len([1 for i in range(len(a)) if a[i] != b[i]]) + 1)