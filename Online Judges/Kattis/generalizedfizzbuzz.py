"""
Author https://github.com/smh997/
https://open.kattis.com/problems/generalizedfizzbuzz
"""

n, a, b = map(int, input().split())
x, y, z = 0, 0, 0
for i in range(1, n+1):
    if i % a == 0 and i % b == 0:
        z += 1
    elif i % a == 0:
        x += 1
    elif i % b == 0:
        y += 1
print(x, y, z)
