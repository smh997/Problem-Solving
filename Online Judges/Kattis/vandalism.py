"""
Author https://github.com/smh997/
https://open.kattis.com/problems/vandalism
"""

inp = input()
print(''.join([ch for ch in 'UAPC' if ch not in inp]))
