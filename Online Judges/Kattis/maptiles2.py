"""
https://open.kattis.com/problems/maptiles2
Author: https://github.com/smh997/
"""
s = input()
l = len(s)
lim = 2 ** (l-1)
x, y = 0, 0
for i in range(l):
    if s[i] == '1':
        x += lim
    elif s[i] == '2':
        y += lim
    elif s[i] == '3':
        x += lim
        y += lim
    lim //= 2
print(l, x, y)