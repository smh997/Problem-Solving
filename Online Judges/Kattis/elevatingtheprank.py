"""
https://open.kattis.com/problems/elevatingtheprank
Author: https://github.com/smh997/
"""

a, b = map(int, input().split())
n = int(input())
li = sorted([int(input()) for i in range(n)])
ans = abs(a-b) * 4
for aa in li:
    if min(a, b) < aa < max(a, b):
        ans += 10
print(ans)