"""
https://open.kattis.com/problems/beekeeper
Author: https://github.com/smh997/
"""
li = ['aa', 'ee', 'ii', 'oo', 'uu', 'yy']
while True:
    n = int(input())
    if not n:
        break
    res = ''
    mx = -1
    for i in range(n):
        s = input()
        cnt = 0
        for a in li:
            cnt += s.count(a)
        if mx < cnt:
            res = s
            mx = cnt
    print(res)