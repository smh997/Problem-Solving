"""
https://open.kattis.com/problems/oddities
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    inp = int(input())
    print(inp, 'is', 'even' if not inp % 2 else 'odd')
