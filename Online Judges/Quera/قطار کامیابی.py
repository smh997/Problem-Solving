"""
https://quera.org/problemset/20257/
Author: https://github.com/smh997/
"""
k, a, b = map(int, input().split())
a, b = min(a, b), max(a, b)
x, y = min(a % k, k - a % k), min(b % k, k - b % k)
if x == k - a % k:
    e = a + x
else:
    e = a - x
if y == b % k:
    f = b - y
else:
    f = b + y
print(min(x + y + abs(f - e) // k, b - a))