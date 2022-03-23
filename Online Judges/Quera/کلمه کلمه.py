"""
https://quera.org/problemset/108665/
Author: https://github.com/smh997/
"""
s = input()
li = ['a', 'e', 'i', 'o', 'u']
p = 0
for ch in s:
    if ch in li:
        p += 1
print(1 << p)
