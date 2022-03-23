"""
https://quera.org/problemset/8358/
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
s = 0
for a in li:
    if a < 0:
        s += 1
print(s * (n - 1))
