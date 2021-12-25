"""
https://open.kattis.com/problems/prerequisites
Author: https://github.com/smh997/
"""
while True:
    line = input()
    if line == '0':
        break
    k, m = map(int, line.split())
    selectedlis = input().split()
    req = []
    for i in range(m):
        req.append(input().split())
    flag = True
    for r in req:
        c = int(r[0])
        need = int(r[1])
        li = r[2:]
        if need:
            for a in li:
                if a in selectedlis:
                    need -= 1
                    if not need:
                        break
        if need > 0:
            flag = False
            print('no')
            break
    if flag:
        print('yes')
