"""
https://open.kattis.com/problems/doublepassword
Author: https://github.com/smh997/
"""

a, b = input(), input()
print(2**sum([int(a[i] != b[i]) for i in range(4)]))