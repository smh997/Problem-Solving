"""
Author https://github.com/smh997/
https://open.kattis.com/problems/pythagoreanproblem
"""

from math import fabs

a, b = map(int, input().split())
a, b = max(a, b), min(a, b)
x = (a * a - b * b) ** 0.5
y = (a * a + b * b) ** 0.5
if fabs(a - b) < 1e-9:
    print("Pythagoras is sad :(")
    exit(0)
if fabs(x - int(x)) < 1e-9:
    print(int(x))
elif fabs(y - int(y)) < 1e-9:
    print(int(y))
else:
    print("Pythagoras is sad :(")
