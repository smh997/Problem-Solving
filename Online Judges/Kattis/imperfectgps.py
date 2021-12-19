"""
https://open.kattis.com/problems/imperfectgps
Author: https://github.com/smh997/
"""
def calc(x1, y1, x2, y2):
    return ((x1-x2)**2+(y1-y2)**2)**0.5


n, t = map(int, input().split())
points = []
gpspoints = []
origdist = 0
tillnow = 0

for i in range(n):
    x, y, ti = map(int, input().split())
    points.append((x, y, ti))
    if i > 0:
        c = calc(points[i][0], points[i][1], points[i-1][0], points[i-1][1])
        origdist += c
        while tillnow < ti:
            m = ((tillnow-points[i-1][2])/(points[i][2]-points[i-1][2]))
            newx = m * (points[i][0]-points[i-1][0]) + points[i-1][0]
            newy = m * (points[i][1] - points[i - 1][1]) + points[i - 1][1]
            gpspoints.append((newx, newy))
            tillnow += t
    else:
        gpspoints.append((x, y))
        tillnow += t
gpspoints.append((points[-1][0], points[-1][1]))
gpsdist = 0
for i in range(1, len(gpspoints)):
    gpsdist += calc(gpspoints[i-1][0], gpspoints[i-1][1], gpspoints[i][0], gpspoints[i][1])
print("%.6f" % (100 * abs(1.0 - gpsdist/origdist)))



