"""
https://open.kattis.com/problems/touchscreenkeyboard
Author: https://github.com/smh997/
"""
dist = {}
li = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm']
for i in range(3):
    for j in range(len(li[i])):
        for k in range(3):
            for l in range(len(li[k])):
                dist[(li[i][j], li[k][l])] = abs(i-k) + abs(l-j)
t = int(input())
for _ in range(t):
    s, n = map(str, input().split())
    n = int(n)
    li = []
    for i in range(n):
        ss = input()
        res = 0
        for kk in range(len(s)):
            res += dist[(s[kk], ss[kk])]
        li.append((res, ss))
    li.sort()
    for a in li:
        print(a[1], a[0])
