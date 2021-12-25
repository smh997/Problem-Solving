"""
https://open.kattis.com/problems/powersof2easy
Author: https://github.com/smh997/
"""
n, e = map(int, input().split())
ss = 1 << e
s = str(ss)
c = 0
for i in range(n+1):
    if s in str(i):
        c += 1
print(c)
