"""
https://quera.org/problemset/91712/
Author: https://github.com/smh997/
"""
x1, x2 = map(int, input().split())
if x1 == x2:
    print('Saal Noo Mobarak!')
elif x1 > x2:
    print((x1 - x2) * 'L')
else:
    print((x2 - x1) * 'R')
