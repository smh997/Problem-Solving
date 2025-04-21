"""
https://open.kattis.com/problems/heimilisverk
Author: https://github.com/smh997/
"""

n = int(input())
s = set()
for i in range(n):
    inp = input()
    if inp not in s:
        print(inp)
    s.add(inp)