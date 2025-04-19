"""
https://open.kattis.com/problems/skammstofun
Author: https://github.com/smh997/
"""

n, li = int(input()), input().split()
print(''.join([a[0] for a in li if a[0].isupper()]))