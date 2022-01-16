"""
https://open.kattis.com/problems/toilet
Author: https://github.com/smh997/
"""
s = input()
a, b, c = 0, 0, 0
for i in range(1, len(s)):
    if i == 1 and s[i] != s[i-1]:
        a += 1
    elif i != 1 and s[i] != 'U':
        a += 1
    if s[i] != 'U':
        a += 1
for i in range(1, len(s)):
    if i == 1 and s[i] != s[i - 1]:
        b += 1
    elif i != 1 and s[i] != 'D':
        b += 1
    if s[i] != 'D':
        b += 1
for i in range(1, len(s)):
    if s[i] != s[i - 1]:
        c += 1
print(a)
print(b)
print(c)