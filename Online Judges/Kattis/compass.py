"""
https://open.kattis.com/problems/compass
Author: https://github.com/smh997/
"""
n1 = int(input())
n2 = int(input())
m = min(abs(n1-n2), 360 - abs(n1-n2))
print('-' if m != 180 and ((n1 > n2 and abs(n1-n2) == m) or (n2 > n1 and abs(n1-n2) != m)) else '', end='')
print(m)
