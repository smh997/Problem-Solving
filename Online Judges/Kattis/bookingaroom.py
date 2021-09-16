"""
https://open.kattis.com/problems/bookingaroom
Author: https://github.com/smh997/
"""
r, n = map(int, input().split())
li = []
if n:
    li = sorted([int(input()) for j in range(n)])
else:
    print(1)
    exit(0)
i = 1
for j in range(n):
    if i != li[j]:
        print(i)
        exit(0)
    i += 1
if i <= r:
    print(i)
else:
    print('too late')