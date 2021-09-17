"""
https://open.kattis.com/problems/carousel
Author: https://github.com/smh997/
"""
while True:
    n, m = map(int, input().split())
    if not n:
        break
    resa, resb = -1, -1
    mx = -1
    for i in range(n):
        a, b = map(int, input().split())
        if a > m:
            continue
        if a / b == mx:
            if resa < a:
                resa = a
                resb = b
        elif a / b > mx:
            mx = a / b
            resb = b
            resa = a
    if mx == -1:
        print('No suitable tickets offered')
    else:
        print('Buy ' + str(resa) + ' tickets for $' + str(resb))
