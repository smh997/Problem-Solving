"""
https://open.kattis.com/problems/filip
Author: https://github.com/smh997/
"""
a, b = input().split()
print(max(int(a[::-1]), int(b[::-1])))
