"""
https://open.kattis.com/problems/apaxiaaans
Author: https://github.com/smh997/
"""
s, t, res = input(), '', ''
for a in s:
    if a != t:
        res += a
        t = a
print(res)
