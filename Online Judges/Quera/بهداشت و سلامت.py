"""
https://quera.org/problemset/51865/
Author: https://github.com/smh997/
"""
x = int(input())
n = int(input())
if n == 0:
    print(20)
elif n == 7:
    print(x)
else:
    print(max(0, x - n))
