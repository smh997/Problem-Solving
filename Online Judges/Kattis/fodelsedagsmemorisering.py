"""
https://open.kattis.com/problems/fodelsedagsmemorisering
Author: https://github.com/smh997/
"""
di = dict()
n = int(input())
for i in range(n):
    name, score, date = map(str, input().split())
    score = int(score)
    if date in di:
        if di[date][0] < score:
            di[date] = (score, name)
    else:
        di[date] = (score, name)
li = sorted([a[1] for a in di.values()])
print(len(li))
for a in li:
    print(a)


