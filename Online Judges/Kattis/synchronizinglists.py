"""
https://open.kattis.com/problems/synchronizinglists
Author: https://github.com/smh997/
"""
while True:
    n = int(input())
    if not n:
        break
    li = []
    for i in range(n):
        li.append(int(input()))
    li2 = []
    for i in range(n):
        li2.append(int(input()))
    lis = sorted(li.copy())
    lis2 = sorted(li2.copy())
    mp = {}
    for i in range(n):
        mp[lis[i]] = lis2[i]
    for i in range(n):
        print(mp[li[i]])
    print()
