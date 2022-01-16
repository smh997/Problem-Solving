"""
https://codeforces.com/contest/1139/problem/A
Author: https://github.com/smh997/
"""
n = input()
s = input()
res = 0
for i, c in enumerate(s):
    if not int(c) % 2:
        res += i+1
print(res)