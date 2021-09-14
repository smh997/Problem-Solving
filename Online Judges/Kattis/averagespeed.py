"""
https://open.kattis.com/problems/averagespeed
Author: https://github.com/smh997/
"""
import sys

lines = sys.stdin.readlines()
d = 0
lastt = 0
sp = 0
for line in lines:
    li = line.split()
    if len(li) == 1:
        tm = li[0].split(':')
        t = int(tm[0]) * 3600 + int(tm[1]) * 60 + int(tm[2])
        print(li[0], end=' ')
        print('%.2f' % (d + ((t - lastt) * sp / 3600)), end=' ')
        print('km')
    else:
        tm = li[0].split(':')
        t = int(tm[0]) * 3600 + int(tm[1]) * 60 + int(tm[2])
        d += ((t - lastt) * sp / 3600)
        lastt = t
        sp = int(li[1])
