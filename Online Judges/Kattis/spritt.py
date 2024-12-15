"""
https://open.kattis.com/problems/spritt
Author: https://github.com/smh997/
"""

n, x = map(int, input().split())
a = sum([int(input()) for _ in range(n)])
print('Jebb' if x >= a else 'Neibb')
