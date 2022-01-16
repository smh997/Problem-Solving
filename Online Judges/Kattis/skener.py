"""
https://open.kattis.com/problems/skener
Author: https://github.com/smh997/
"""
r, c, zr, zc = map(int, input().split())
li = [['' for i in range(zc*c)] for j in range(r*zr)]
for i in range(r):
    inp = input()
    for j, cc in enumerate(inp):
        for kr in range(zr):
            for kc in range(zc):
                li[i*zr+kr][j*zc+kc] = cc
for i in range(r*zr):
    print(''.join(li[i]))

