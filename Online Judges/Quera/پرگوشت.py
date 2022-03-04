"""
https://quera.org/problemset/72882/
Author: https://github.com/smh997/
"""
n, m = map(int, input().split())
a, b = 0, 0
for i in range(n):
    a += input().count('*')
for i in range(n):
    b += input().count('*')
print(a, b)
