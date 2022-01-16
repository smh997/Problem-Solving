"""
https://open.kattis.com/problems/biggesttriangle
Author: https://github.com/smh997/
"""

def cross(p, q):
    return (p*q.conjugate()).imag


def intersect(l1, l2):
    d = cross(l1[1]-l1[0], l2[0]-l2[1])
    if abs(d) < 1e-8:
        return None

    num = cross(l2[0]-l1[0], l2[0]-l2[1])

    return l1[0]+(l1[1]-l1[0])*num/d


def area(l1, l2, l3):
    i1 = intersect(l1, l2)
    i2 = intersect(l2, l3)
    i3 = intersect(l3, l1)

    if None in [i1, i2, i3]:
        return 0.0

    return abs(i1-i2) + abs(i2-i3) + abs(i3-i1)


n = int(input())
lines = []

for _ in range(n):
    x1, y1, x2, y2 = map(float, input().split())
    lines.append([complex(x1, y1), complex(x2, y2)])

best = 0.0
for i in range(n):
    for j in range(i):
        for k in range(j):
            best = max(best, area(lines[i], lines[j], lines[k]))

if abs(best) < 1e-8:
    print('no triangle')
else:
    print('%.10f' %best)
