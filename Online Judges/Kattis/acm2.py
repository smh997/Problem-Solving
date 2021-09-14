"""
https://open.kattis.com/problems/acm2
Author: https://github.com/smh997/
"""
n, p = map(int, input().split())
li = list(map(int, input().split()))
if li[p] > 300:
    print(0, 0)
else:
    t = s = li[p]
    ac = 1
    li.remove(li[p])
    li.sort()
    for i in range(n-1):
        if t + li[i] <= 300:
            t += li[i]
            s += t
            ac += 1
    print(ac, s)