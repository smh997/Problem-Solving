"""
Author https://github.com/smh997/
https://open.kattis.com/problems/partialtransmission
"""

n = int(input())
p = int(input())
s = set(list(map(int, input().split())))
for i in range(p, n+p):
    if i not in s:
        print(i)
        exit(0)
