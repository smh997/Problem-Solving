"""
https://open.kattis.com/problems/asciifigurerotation
Author: https://github.com/smh997/
"""
first = True
while True:
    n = int(input())
    if not n:
        break
    if not first:
        print()
    li = []
    mx = 0
    for i in range(n):
        li.append(input())
        mx = max(mx, len(li[i]))
    for i in range(n):
        li[i] += ' ' * (mx - len(li[i]))
    res = ['' for i in range(mx)]
    for i in range(mx):
        for j in range(n):
            if li[n-1-j][i] == '-':
                res[i] += '|'
            elif li[n-1-j][i] == '|':
                res[i] += '-'
            else:
                res[i] += li[n-1-j][i]
    for i in range(mx):
        print(res[i].rstrip())
    first = False
