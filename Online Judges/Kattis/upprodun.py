"""
https://open.kattis.com/problems/upprodun
Author: https://github.com/smh997/
"""

n = int(input())
m = int(input())
for i in range(n):
    print('*' * (m//n) + ('*' if i < m%n else ''))
