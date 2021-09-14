"""
https://open.kattis.com/problems/armystrengthhard
Author: https://github.com/smh997/
"""
t = int(input())
for _ in range(t):
    ssss = input()
    g, m = map(int, input().split())
    gg = sorted(list(map(int, input().split())))
    mm = sorted(list(map(int, input().split())))
    ig = 0
    im = 0
    while im != m and ig != g:
        if gg[ig] >= mm[im]:
            im += 1
        else:
            ig += 1
    if im == m:
        print('Godzilla')
    else:
        print('MechaGodzilla')
