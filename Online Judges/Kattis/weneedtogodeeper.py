"""
https://open.kattis.com/problems/weneedtogodeeper
Author: https://github.com/smh997/
"""

x = int(input())
ans = 0
for w in range(4, 24):
    for h in range(5, 24):
        if 2*w + 2*h - 4 <= x:
            ans += 1
print(ans)