"""
https://quera.org/problemset/18311/
Author: https://github.com/smh997/
"""
tim = [True] * (24 * 3600)
for _ in range(3):
    li = input().split()
    for i in range(1, 2 * int(li[0]) + 1, 2):
        t = list(map(int, li[i].split(':')))
        st = t[0] * 3600 + t[1] * 60 + t[2]
        t = list(map(int, li[i+1].split(':')))
        et = t[0] * 3600 + t[1] * 60 + t[2]
        for k in range(st, et+1):
            tim[k] = False
res = -1
for i in range(24 * 3600 - 15 * 60 + 1):
    res = i
    for j in range(15 * 60):
        if not tim[i + j]:
            res = -1
            break
    if res != -1:
        break
if res == -1:
    print(-1)
else:
    print('%02d:%02d:%02d' % (res // 3600, res % 3600 // 60, res % 3600 % 60))
