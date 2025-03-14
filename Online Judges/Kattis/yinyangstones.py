"""
https://open.kattis.com/problems/yinyangstones
Author: https://github.com/smh997/
"""

s = input()
w, b = 0, 0
for ch in s:
    if ch == 'B':
        b += 1
    else:
        w += 1
    if b > 1 and b == w + 1:
        w = 0
        b = 1
    elif w > 1 and w == b + 1:
        w = 1
        b = 0
print(1 if w == 1 and b == 1 else 0)