"""
https://open.kattis.com/problems/snowfall
Author: https://github.com/smh997/
"""

n = int(input())
ans = 0
for i in range(n):
    t, a = map(int, input().split())
    ans += (1-t) * a
    ans = max(0, ans - t * a)
print(ans)