"""
https://open.kattis.com/problems/justaminute
Author: https://github.com/smh997/
"""
n = int(input())
a, b = 0, 0
for i in range(n):
    m, s = map(int, input().split())
    a += m
    b += s / 60
if b <= a:
    print('measurement error')
else:
    print('%.8f' % (b / a))
