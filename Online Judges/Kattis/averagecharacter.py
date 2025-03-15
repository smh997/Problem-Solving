"""
https://open.kattis.com/problems/averagecharacter
Author: https://github.com/smh997/
"""

s = input()
print(chr(sum([ord(c) for c in s]) // len(s)))