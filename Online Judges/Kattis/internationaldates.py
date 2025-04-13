"""
https://open.kattis.com/problems/internationaldates
Author: https://github.com/smh997/
"""

a, b, c = map(int, input().split('/'))
print('EU' if a > 12 else 'US' if b > 12 else 'either')
