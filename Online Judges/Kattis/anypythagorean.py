"""
https://open.kattis.com/problems/anypythagorean
Author: https://github.com/smh997/
"""

n = int(input())
for a in range(1, n):
    for b in range(a, n-a):
        c = n - (a + b)
        if a * a + b * b == c * c:
            print(a, b, c)
            exit(0)
print(0, 0, 0)