"""
https://open.kattis.com/problems/weakvertices
Author: https://github.com/smh997/
"""
while True:
    n = int(input())
    if n == -1:
        break
    li = []
    mosalasi = []
    are = False
    for i in range(n):
        li.append(list(map(int, input().split())))
    for i in range(n):
        are = False
        if i in mosalasi:
            continue
        for j in range(len(li[i])):
            if li[i][j]:
                for k in range(len(li[j])):
                    if li[j][k] and k != i:
                        if li[i][k]:
                            mosalasi.append(i)
                            are = True
                            break
            if are:
                break
    res = [a for a in range(n) if a not in mosalasi]
    for a in res:
        print(a, end=' ')
    print()