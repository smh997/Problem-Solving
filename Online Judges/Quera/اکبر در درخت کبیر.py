"""
https://quera.org/problemset/31026/
Author: https://github.com/smh997/
"""
n = int(input())
a = input()
m = int(input())
b = input()
con = 0
for i in range(min(n, m)):
    if a[i] != b[i]:
        break
    con += 1
print((n - con) + (m - con))
