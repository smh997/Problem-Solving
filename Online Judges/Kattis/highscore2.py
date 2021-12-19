"""
https://open.kattis.com/problems/highscore2
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    a, b, c, d = map(int, input().split())
    li = [a, b, c]
    li.sort()
    t = 0
    res = li[0]**2 + li[1]**2 + (li[2]+d)**2 + 7*li[0]
    while t < 1000000 and d > 0:
        t += 1
        li[0] += 1
        d -= 1
        li.sort()
        res = max(res, li[0]**2+li[1]**2+(li[2]+d)**2+7*li[0])
    print(res)