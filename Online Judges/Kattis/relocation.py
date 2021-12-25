"""
https://open.kattis.com/problems/relocation
Author: https://github.com/smh997/
"""
n, q = map(int, input().split())
li = list(map(int, input().split()))
for i in range(q):
    a, b, c = map(int, input().split())
    if a == 1:
        li[b-1] = c
    else:
        print(abs(li[b-1]-li[c-1]))