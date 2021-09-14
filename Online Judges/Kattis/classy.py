"""
https://open.kattis.com/problems/classy
Author: https://github.com/smh997/
"""

t = int(input())
for i in range(t):
    n = int(input())
    mp = {}
    li2 = []
    tmp = []
    mx = 0
    for p in range(n):
        person, hic, _ = map(str, input().split())
        li = hic.split('-')
        tmp.append((person[:-1], li))
        mx = max(mx, len(li))
    for p in tmp:
        person = p[0]
        li = p[1]
        s = ''
        for k in range(len(li)):
            if li[k] == 'upper':
                s = '1' + s
            elif li[k] == 'middle':
                s = '2' + s
            else:
                s = '3' + s
        s += ('2'*(mx-len(li)))
        mp[s] = person
        li2.append((s, person))
    li2.sort()
    for p in li2:
        print(p[1])
    print('==============================')