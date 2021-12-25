"""
https://open.kattis.com/problems/oddgnome
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    li = list(map(int, input().split()))
    le = li[0]
    li = li[1:]
    for j in range(1, le-1):
        tmp = li.copy()
        L = tmp[:j]
        R = tmp[j+1:]
        tmp = L+R
        if tmp == sorted(tmp):
            print(j+1)
            break

