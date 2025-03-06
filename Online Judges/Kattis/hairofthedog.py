"""
https://open.kattis.com/problems/hairofthedog
Author: https://github.com/smh997/
"""

n = int(input())
ans = 0
f = False
for _ in range(n):
    if input() == 'sober':
        ans += 1 if f else 0
        f = False
    else:
        f = True
print(ans)