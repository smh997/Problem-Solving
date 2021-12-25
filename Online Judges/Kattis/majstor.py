"""
https://open.kattis.com/problems/majstor
Author: https://github.com/smh997/
"""
def calc(ch1, ch2):
    if ch1 == ch2:
        return 1
    if (ch1 == 'R' and ch2 == 'S') or (ch1 == 'S' and ch2 == 'P') or (ch1 == 'P' and ch2 == 'R'):
        return 2
    return 0

r = int(input())
sw = input()
fr = []
n = int(input())
res1 = 0
res2 = 0
for i in range(n):
    fr.append(input())
    for j in range(r):
        res1 += calc(sw[j], fr[i][j])
print(res1)
prs = ['S', 'P', 'R']
for j in range(r):
    msc = 0
    for a in prs:
        sc = 0
        for i in range(n):
            sc += calc(a, fr[i][j])
        msc = max(sc, msc)
    res2 += msc
print(res2)