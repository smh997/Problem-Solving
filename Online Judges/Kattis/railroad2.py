"""
https://open.kattis.com/problems/railroad2
Author: https://github.com/smh997/
"""
a, b = map(int, input().split())
print('possible' if not b % 2 else 'impossible')
