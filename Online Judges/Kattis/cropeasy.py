"""
https://open.kattis.com/problems/cropeasy
Author: https://github.com/smh997/
"""
def compute():
    n, a, b, c, d, x0, y0, m = map(int, input().split())
    pts = []
    pts.append([x0,y0])
    x = x0
    y = y0
    for i in range(1, n):
        x = (a*x+b)%m
        y = (c*y+d)%m
        pts.append([x,y])
    c = 0
    for i in range(len(pts)):
        for j in range(i+1,len(pts)):
            for k in range(j+1,len(pts)):
                if (pts[i][0]+pts[j][0]+pts[k][0])%3 == 0:
                    if (pts[i][1]+pts[j][1]+pts[k][1])%3 == 0:
                        c+=1
    return c

for i in range(int(input())):
    print("Case #%d: %d" % (i+1, compute()))
