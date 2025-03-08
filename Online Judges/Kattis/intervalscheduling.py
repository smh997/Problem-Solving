"""
https://open.kattis.com/problems/intervalscheduling
Author: https://github.com/smh997/
"""

n = int(input())
li = []
for i in range(n):
    a, b = map(int, input().split())
    li.append((b, a))
li.sort()
ans = 1
cur = li[0][0]
for i in range(1, n):
    if li[i][1] >= cur:
        cur = li[i][0]
        ans += 1
print(ans)