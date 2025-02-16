"""
https://open.kattis.com/problems/countdoubles
Author: https://github.com/smh997/
"""

n, m = map(int, input().split())
a = list(map(int, input().split()))
c = sum([1 for e in a[:m] if e % 2 == 0])
ans = 1 if c >= 2 else 0
for i in range(m, n):
    if a[i] % 2 == 0:
        c += 1
    if a[i-m] % 2 == 0:
        c -= 1
    if c >= 2:
        ans += 1
print(ans)