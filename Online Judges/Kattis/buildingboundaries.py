"""
https://open.kattis.com/problems/buildingboundaries
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    v = list(map(int, input().split()))
    v = [(v[2*i], v[2*i+1]) for i in range(3)]
    res = 1e20
    for s in range(3):
        a = v[s]
        b = v[(s+1) % 3]
        c = v[(s+2) % 3]
        for ra in range(2):
            for rb in range(2):
                for rc in range(2):
                    w = b[rb] + c[rc]
                    h = max(b[not rb], c[not rc])
                    res = min(res, (a[ra]+w) * max(a[not ra], h))
                    res = min(res, max(a[ra], w) * (a[not ra] + h))
    print(res)
