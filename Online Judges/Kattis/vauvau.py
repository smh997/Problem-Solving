"""
https://open.kattis.com/problems/vauvau
Author: https://github.com/smh997/
"""
a, b, c, d = map(int, input().split())
p, m, g = map(int, input().split())
flag = False
if 0 != p % (a+b) <= a:
    if 0 != p % (c+d) <= c:
        print('both')
    else:
        print('one')
    flag = True
if not flag and 0 != p % (c+d) <= c:
    if 0 != p % (a+b) <= a:
        print('both')
    else:
        print('one')
    flag = True
if not flag:
    print('none')
flag = False
if 0 != m % (a+b) <= a:
    if 0 != m % (c+d) <= c:
        print('both')
    else:
        print('one')
    flag = True
if not flag and 0 != m % (c+d) <= c:
    if 0 != m % (a+b) <= a:
        print('both')
    else:
        print('one')
    flag = True
if not flag:
    print('none')
flag = False
if 0 != g % (a+b) <= a:
    if 0 != g % (c+d) <= c:
        print('both')
    else:
        print('one')
    flag = True
if not flag and 0 != g % (c+d) <= c:
    if 0 != g % (a+b) <= a:
        print('both')
    else:
        print('one')
    flag = True
if not flag:
    print('none')
