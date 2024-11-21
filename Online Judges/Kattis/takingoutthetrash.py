"""
https://open.kattis.com/problems/takingoutthetrash
Author: https://github.com/smh997/
"""

n, m = map(int, input().split())
w = sorted(list(map(int, input().split())))
i, j = 0, len(w)-1
ans = 0
while i < j:
    if w[i] + w[j] <= m:
        i += 1
    j -= 1
    ans += 1
if i == j:
    ans += 1
print(ans)