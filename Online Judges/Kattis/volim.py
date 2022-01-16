"""
https://open.kattis.com/problems/volim
Author: https://github.com/smh997/
"""
k = int(input())
n = int(input())
timer = 0
for i in range(n):
    t, s = map(str, input().split())
    t = int(t)
    if timer + t > 210:
        print(k)
        break
    elif timer + t == 210 and s == 'T':
        print(1 if (k+1)==9 else k+1)
        break
    elif s == 'T':
        k += 1
        if k == 9:
            k = 1
    timer += t


