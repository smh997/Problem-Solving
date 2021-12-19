"""
https://open.kattis.com/problems/liga
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    tot, w, d, l, p = map(str, input().split())
    wmx, wmi, dmx, dmi = 0, 0, 0, 0
    wmx = 100 if w == '?' else w
    wmi = 0 if w == '?' else w
    dmx = 100 if d == '?' else d
    dmi = 0 if d == '?' else d
    if tot == '?' and l == '?':
        l = 0
    for j in range(int(wmi), int(wmx)+1):
        for k in range(int(dmi), int(dmx)+1):
            tota = j + k + int(l) if tot == '?' else int(tot)
            la = tota - j - k if l == '?' else int(l)
            pa = 3*j + k if p == '?' else int(p)
            if tota == j + k + la and 100 >= tota >= 0 and 100 >= la >= 0 and pa == 3 * j + k:
                print(tota, j, k, la, pa)
