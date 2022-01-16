"""
https://open.kattis.com/problems/watchdog
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    n, h = map(int, input().split())
    hatches = []
    mark = [[False for k in range(n)] for j in range(n)]
    for j in range(h):
        x, y = map(int, input().split())
        hatches.append((x, y))
        mark[x][y] = True
    flag = True
    for x in range(1, n):
        for y in range(1, n):
            if mark[x][y]:
                continue
            mx = 0
            for k in range(h):
                mx = max(mx, ((hatches[k][0] - x) ** 2 + (hatches[k][1] - y) ** 2) ** 0.5)
            if mx <= min(min(x, n-x), min(y, n-y)):
                flag = False
                print(x, y)
                break
        if not flag:
            break
    if flag:
        print('poodle')

