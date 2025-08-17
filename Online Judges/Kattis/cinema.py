"""
Author https://github.com/smh997/
https://open.kattis.com/problems/cinema
"""

n, m = map(int, input().split())
li = list(map(int, input().split()))
s = 0
ans = 0
for i in range(m):
    if s + li[i] > n:
        ans += 1
        continue
    s += li[i]
print(ans)
