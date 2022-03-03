"""
https://open.kattis.com/problems/simplecronspec
Author: https://github.com/smh997/
"""

res2 = 0
res = [0] * 24 * 60 * 60
n = int(input())
for i in range(n):
    h, m, s = input().split()
    t = 1
    hours, minutes, seconds = [], [], []
    if h == '*':
        hours = list(range(24))
    else:
        tmp = h.split(',')
        for hh in tmp:
            if '-' in hh:
                a, b = map(int, hh.split('-'))
                hours += list(range(a, b+1))
            else:
                hours.append(int(hh))
    t *= len(hours)
    if m == '*':
        minutes = list(range(60))
    else:
        tmp = m.split(',')
        for mm in tmp:
            if '-' in mm:
                a, b = map(int, mm.split('-'))
                minutes += list(range(a, b+1))
            else:
                minutes.append(int(mm))
    t *= len(minutes)
    if s == '*':
        seconds = list(range(60))
    else:
        tmp = s.split(',')
        for ss in tmp:
            if '-' in ss:
                a, b = map(int, ss.split('-'))
                seconds += list(range(a, b+1))
            else:
                seconds.append(int(ss))
    t *= len(seconds)
    res2 += t
    for hour in hours:
        for minute in minutes:
            for second in seconds:
                res[hour * 3600 + minute * 60 + second] = 1
print(sum(res), res2)
