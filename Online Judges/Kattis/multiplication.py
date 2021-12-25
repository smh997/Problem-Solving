"""
https://open.kattis.com/problems/multiplication
Author: https://github.com/smh997/
"""
import math
while True:
    n, m = map(int, input().split())
    if n == 0:
        break
    c = int(math.ceil(math.log10(n)))
    r = int(math.ceil(math.log10(m)))
    if c == 0:
        c = 1
    if r == 0:
        r = 1
    lin = [n // (10 ** i) % 10 for i in range(c)]
    lim = [m // (10 ** i) % 10 for i in range(r)]
    lin.reverse()
    lim.reverse()
    li1, li2 = [], []
    for i in range(r):
        lis, lis2 = [], []
        for j in range(c):
            mul = lim[i] * lin[j]
            lis.append(mul // 10)
            lis2.append(mul % 10)
        li1.append(lis)
        li2.append(lis2)
    res = n * m
    rowbreaker = [False for i in range(r)]
    for i in range(r):
        if res >= 10 ** (c+i):
            rowbreaker[-i-1] = True
    print('+-' + (c * 4 + 1) * '-' + '-+')
    print('| ', end=' ')
    for i in range(c):
        print(' ' + str(lin[i]) + '  ', end='')
    print(' |')
    print('| +', end='')
    for i in range(c):
        print('---+', end='')
    print(' |')
    for i in range(r):
        for j in range(3):
            print('|', end='')
            if j == 0:
                if i > 0 and rowbreaker[i-1]:
                    print('/', end='')
                else:
                    print(' ', end='')
            elif j == 2:
                if rowbreaker[i]:
                    print(str(res // (10 ** (r+c-i-1)) % 10), end='')
                else:
                    print(' ', end='')
            else:
                print(' ', end='')
            print('|', end='')
            for k in range(c):
                if j == 0:
                    print(str(li1[i][k]) + ' /|', end='')
                elif j == 1:
                    print(' / |', end='')
                else:
                    print('/ ' + str(li2[i][k]) + '|', end='')
            if j == 0 or j == 2:
                print(' |')
            else:
                print(str(lim[i]) + '|')
        print('| +', end='')
        for i in range(c):
            print('---+', end='')
        print(' |')

    print('|', end='')
    if rowbreaker[r-1]:
        print('/', end='')
    else:
        print(' ', end='')
    for i in range(c):
        if i > 0:
            print('/', end='')
        print(' ' + str(res // (10 ** (c-i-1)) % 10) + ' ', end='')
    print('   |')
    print('+-' + (c * 4 + 1) * '-' + '-+')
