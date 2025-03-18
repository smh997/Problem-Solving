"""
https://open.kattis.com/problems/endurvinnsla
Author: https://github.com/smh997/
"""

s, p, n = input(), float(input()), int(input())
print('Jebb' if [input() for i in range(n)].count('ekki plast') <= p * n else 'Neibb')