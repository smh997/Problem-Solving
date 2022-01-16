"""
https://open.kattis.com/problems/temperature
Author: https://github.com/smh997/
"""
x, y = map(int, input().split())
if y-1 == 0 and x == 0:
    print('ALL GOOD')
elif y-1 == 0:
    print('IMPOSSIBLE')
else:
    print((-x)/(y-1))
