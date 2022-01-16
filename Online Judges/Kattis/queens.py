"""
https://open.kattis.com/problems/queens
Author: https://github.com/smh997/
"""
n = int(input())
x = [False for i in range(n)]
y = [False for i in range(n)]
yx = [False for i in range(2*n)]
xy = [False for i in range(2*n)]
ans = True
for i in range(n):
    xx, yy = map(int, input().split())
    if y[yy]:
        ans = False
    if x[xx]:
        ans = False
    if yx[yy-xx+n-1]:
        ans = False
    if xy[yy + xx]:
        ans = False
    y[yy] = True
    x[xx] = True
    yx[yy-xx+n-1] = True
    xy[yy + xx] = True
print('CORRECT' if ans else 'INCORRECT')