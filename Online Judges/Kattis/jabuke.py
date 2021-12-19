"""
https://open.kattis.com/problems/jabuke
Author: https://github.com/smh997/
"""
xa, ya = map(int, input().split())
xb, yb = map(int, input().split())
xc, yc = map(int, input().split())
n = int(input())
area = abs(xa*(yb-yc)+xb*(yc-ya)+xc*(ya-yb))/2
c = 0
for i in range(n):
    xt, yt = map(int, input().split())
    res = 0
    res += abs(xt * (yb - yc) + xb * (yc - yt) + xc * (yt - yb)) / 2
    res += abs(xa * (yt - yc) + xt * (yc - ya) + xc * (ya - yt)) / 2
    res += abs(xa * (yb - yt) + xb * (yt - ya) + xt * (ya - yb)) / 2
    if res == area:
        c += 1
print(area)
print(c)
