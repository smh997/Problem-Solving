"""
https://open.kattis.com/problems/namnsdag
Author: https://github.com/smh997/
"""

name = input()
n = int(input())
li = [input() for _ in range(n)]
for i in range(n):
    a = li[i]
    if len(a) != len(name):
        continue
    if len([j for j in range(len(a)) if a[j] != name[j]]) <= 1:
        print(i+1)
        break