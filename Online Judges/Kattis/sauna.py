"""
https://open.kattis.com/problems/sauna
Author: https://github.com/smh997/
"""

n = int(input())
mi, mx = -1, 1e6
for _ in range(n):
    a, b = map(int, input().split())
    mi = max(mi, a)
    mx = min(mx, b)
if mi > mx:
    print('bad news')
else:
    print(mx - mi + 1, mi)