"""
https://quera.org/problemset/2439/
Author: https://github.com/smh997/
"""
n, x = map(str, input().split())
a = 1
for i in range(1, int(n) + 1):
    a *= i

print(str(a).count(x))
