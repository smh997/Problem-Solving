"""
https://open.kattis.com/problems/peningar
Author: https://github.com/smh997/
"""

n, d = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
i = 0
while True:
    if not a[i]:
        print(ans)
        break
    ans += a[i]
    a[i] = 0
    i = (i + d) % n