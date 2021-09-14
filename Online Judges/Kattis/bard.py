"""
https://open.kattis.com/problems/bard
Author: https://github.com/smh997/
"""
n = int(input())
m = int(input())
li = [0] * (n+1)
b = 0
for i in range(m):
    inp = list(map(int, input().split()))[1:]
    if 1 in inp:
        b += 1
        for j in inp:
            li[j] += 1
    else:
        for j in inp:
            li[j] = b
for i, a in enumerate(li):
    if a == b:
        print(i)
