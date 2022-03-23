"""
https://quera.org/problemset/49028/
Author: https://github.com/smh997/
"""
n = int(input())
a = int(input())
s = 0
for i in range(1, n):
    c = int(input())
    if c != a:
        s += 1
        a = c
print(s)
