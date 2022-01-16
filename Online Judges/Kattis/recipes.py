"""
https://open.kattis.com/problems/recipes
Author: https://github.com/smh997/
"""
t = int(input())
for tt in range(t):
    r, p, d = map(int, input().split())
    factor = d / p
    rec = []
    mainw = 0
    for i in range(r):
        li = input().split()
        name, w, perc = li[0], float(li[1]), float(li[2])
        rec.append((name, w, perc))
        if perc == 100:
            mainw = w * factor
    print('Recipe #', tt+1)
    for rr in rec:
        print(rr[0], end=' ')
        print('%.1f' % (rr[2] * mainw / 100))
    print('----------------------------------------')
