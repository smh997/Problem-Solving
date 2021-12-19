"""
https://open.kattis.com/problems/judgingmoose
Author: https://github.com/smh997/
"""
a, b = map(int, input().split())
print('Not a moose' if not (a + b) else 'Even' if a == b else 'Odd', 2 * max(a, b) if a + b else '')