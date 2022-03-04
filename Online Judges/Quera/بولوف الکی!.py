"""
https://quera.org/problemset/9595/
Author: https://github.com/smh997/
"""
n = int(input())
c = 0
for i in range(n):
    q = input()
    a = input()
    q = q.replace(" ", "")
    a = a.replace(" ", "")
    if a != q:
        c += 1
print(c)
