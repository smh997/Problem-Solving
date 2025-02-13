"""
https://open.kattis.com/problems/scalingrecipe
Author: https://github.com/smh997/
"""

n, x, y = map(int, input().split())
for i in range(n):
    a = int(input())
    print(int(a * y / x))
