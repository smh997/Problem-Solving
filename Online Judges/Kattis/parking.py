"""
https://open.kattis.com/problems/parking
Author: https://github.com/smh997/
"""
a, b, c = map(int, input().split())
b *= 2
c *= 3
ss, ee = [], []
for i in range(3):
    s, e = map(int, input().split())
    ss.append(s)
    ee.append(e)
su = 0
aa, bb, cc = 0, 0, 0
for i in range(1, 101):
    if i in ss:
        su += ss.count(i)
    if i in ee:
        su -= ee.count(i)
    if su == 1:
        aa += 1
    elif su == 2:
        bb += 1
    elif su == 3:
        cc += 1
print(aa*a + bb*b + cc*c)