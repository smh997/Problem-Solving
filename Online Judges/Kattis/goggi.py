"""
Author https://github.com/smh997/
https://open.kattis.com/problems/goggi
"""

inp = input().split()
a, b = int(inp[0]), int(inp[2])
print('<' if a < b else '>' if a > b else 'Goggi svangur!')
