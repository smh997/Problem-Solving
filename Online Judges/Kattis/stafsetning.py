"""
https://open.kattis.com/problems/stafsetning
Author: https://github.com/smh997/
"""

n, m, k = map(int, input().split())
li = list(map(int, input().split()))
if k < m:
    print(":(")
    exit(0)
ans = 0
c = k // m
cap = 0
for i in range(n):
    cap += li[i]
    if cap > c:
        ans += cap // c
        cap = cap % c
ans += cap // c + (1 if cap % c else 0)
print(ans)