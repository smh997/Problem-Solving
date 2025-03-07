"""
https://open.kattis.com/problems/intuitiveelements
Author: https://github.com/smh997/
"""

t = int(input())
for _ in range(t):
    a, b = input(), input()
    print('NO' if [ch for ch in b if ch not in a] else 'YES')
