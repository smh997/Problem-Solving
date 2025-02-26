"""
https://open.kattis.com/problems/composedrhythms
Author: https://github.com/smh997/
"""

n = int(input())
if n % 2:
    li = ['3'] + ['2'] * ((n-3)//2)
else:
    li = ['2'] * (n // 2)
print(len(li))
print(' '.join(li))