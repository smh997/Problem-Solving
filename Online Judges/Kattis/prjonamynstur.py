"""
https://open.kattis.com/problems/prjonamynstur
Author: https://github.com/smh997/
"""

mp = {'.': 20, 'O': 10, 'A': 35, '^': 5, 'v': 22}
n, m = map(int, input().split())
ans = 0
for _ in range(n):
    for ch in input():
        ans += mp[ch] if ch in mp else 25
print(ans)