"""
https://open.kattis.com/problems/hindex
Author: https://github.com/smh997/
"""
n = int(input())
li = sorted([int(input()) for i in range(n)])
m = 0
for i in range(n):
    m = max(m, min(li[i], n-i))
print(m)