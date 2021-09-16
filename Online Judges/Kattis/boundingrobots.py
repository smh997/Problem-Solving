"""
https://open.kattis.com/problems/boundingrobots
Author: https://github.com/smh997/
"""
while True:
    w, h = map(int, input().split())
    if (w, h) == (0, 0):
        break
    xt, yt = 0, 0
    xa, ya = 0, 0
    n = int(input())
    for i in range(n):
        x, y = map(str, input().split())
        y = int(y)
        if x == 'u':
            yt += y
            ya = min(h-1, ya + y)
        elif x == 'r':
            xt += y
            xa = min(w - 1, xa + y)
        elif x == 'd':
            yt -= y
            ya = max(0, ya - y)
        else:
            xt -= y
            xa = max(0, xa - y)
    print('Robot thinks', xt, yt)
    print('Actually at', xa, ya)
    print()
