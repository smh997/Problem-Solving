"""
https://open.kattis.com/problems/vote
Author: https://github.com/smh997/
"""
t = int(input())
for _ in range(t):
    n = int(input())
    mx = -1
    ss = 0
    mxi = -1
    for i in range(n):
        v = int(input())
        ss += v
        if v == mx:
            mxi = -1
        if v > mx:
            mx = v
            mxi = i
    if mxi == -1:
        print('no winner')
    elif 2 * mx > ss:
        print('majority winner', mxi+1)
    else:
        print('minority winner', mxi+1)
