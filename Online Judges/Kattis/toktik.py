"""
https://open.kattis.com/problems/toktik
Author: https://github.com/smh997/
"""

mp = dict()
n = int(input())
for i in range(n):
    s, a = map(str, input().split())
    a = int(a)
    if s not in mp:
        mp[s] = 0
    mp[s] += a
mx, ans = 0, ""
for s in mp:
    if mx < mp[s]:
        mx = mp[s]
        ans = s
print(ans)