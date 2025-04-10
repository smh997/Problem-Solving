"""
https://open.kattis.com/problems/squarepeg
Author: https://github.com/smh997/
"""

l, r = map(int, input().split())
print('fits' if l * l <= 2 * r * r else 'nope')