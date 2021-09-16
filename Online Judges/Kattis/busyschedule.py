"""
https://open.kattis.com/problems/busyschedule
Author: https://github.com/smh997/
"""
while True:
    n = int(input())
    if n == 0:
        break
    am = []
    pm = []
    for i in range(n):
        a, b = map(str, input().split())
        h, m = map(int, a.split(':'))
        a = '{:0>2d}'.format(h) + ':' + '{:0>2d}'.format(m)
        if b == 'a.m.':
            am.append(a)
        else:
            pm.append(a)
    am.sort()
    pm.sort()
    ita = 0
    itp = 0
    for i in range(len(am)):
        if am[i].startswith('12'):
            ita = i
            break
    for i in range(len(pm)):
        if pm[i].startswith('12'):
            itp = i
            break
    na = len(am)
    np = len(pm)
    for i in range(ita, ita + na):
        h, m = map(int, am[i % na].split(':'))
        aa = str(h) + ':' + '{:0>2d}'.format(m)
        print(aa, 'a.m.')
    for i in range(itp, itp + np):
        h, m = map(int, pm[i % np].split(':'))
        aa = str(h) + ':' + '{:0>2d}'.format(m)
        print(aa, 'p.m.')
    print()