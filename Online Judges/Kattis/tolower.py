"""
https://open.kattis.com/problems/tolower
Author: https://github.com/smh997/
"""
p, t = map(int, input().split())
res = 0
b = True
for i in range(p):
    b = True
    for j in range(t):
        s = input()
        if len(s) > 1 and s[1:] != s[1:].lower():
            b = False
    if b:
        res += 1
print(res)