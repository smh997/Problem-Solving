"""
https://open.kattis.com/problems/warehouse
Author: https://github.com/smh997/
"""
import operator
d = dict()
t = int(input())
for i in range(t):
    d.clear()
    n = int(input())
    for i in range(n):
        k, v = input().split()
        v = int(v)
        if k not in d:
            d[k] = 0
        d[k] += v
    print(len(d))
    dd = sorted(d.items(), key=operator.itemgetter(1), reverse=True)
    s = 0
    li = []
    for k in dd:
        if s == 0:
            li.append(k[0])
            s = k[1]
        elif s == k[1]:
            li.append(k[0])
        else:
            li.sort()
            for a in li:
                print(a, s)
            li.clear()
            li.append(k[0])
            s = k[1]
    li.sort()
    for a in li:
        print(a, s)

