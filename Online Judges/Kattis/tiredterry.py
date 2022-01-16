"""
https://open.kattis.com/problems/tiredterry
Author: https://github.com/smh997/
"""
n, p, d = map(int, input().split())
s = 2 * input()
a = 0
res = 0
for i in range(2*n):
    if s[i] == 'Z':
        a += 1
    if i-p >= 0 and s[i-p] == 'Z':
        a -= 1
    if i >= n and a < d:
        res += 1
print(res)