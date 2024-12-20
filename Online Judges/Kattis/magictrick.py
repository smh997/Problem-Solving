"""
https://open.kattis.com/problems/magictrick
Author: https://github.com/smh997/
"""

s = input()
for ch in s:
    if s.count(ch) > 1:
        print(0)
        exit(0)
print(1)