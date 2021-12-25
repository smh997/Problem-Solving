"""
https://open.kattis.com/problems/rhyming
Author: https://github.com/smh997/
"""
s = input()
e = int(input())
li = []
for i in range(e):
    li.append(input().split())
p = int(input())
lis = [False for i in range(e)]
for i in range(e):
    for item in li[i]:
        if s.endswith(item):
            lis[i] = True
            break
for i in range(p):
    phs = input().split()[-1]
    res = False
    for j in range(e):
        if lis[j]:
            for item in li[j]:
                if phs.endswith(item):
                    res = True
                    break
        if res:
            break
    if res:
        print('YES')
    else:
        print('NO')