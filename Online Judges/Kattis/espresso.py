"""
https://open.kattis.com/problems/espresso
Author: https://github.com/smh997/
"""

n, s = map(int, input().split())
c = s
ans = 0
for i in range(n):
    order = input()
    a = (int(order[0]) + (1 if len(order) > 1 else 0))
    if c < a:
        c = s - a
        ans += 1
    else:
        c -= a
print(ans)