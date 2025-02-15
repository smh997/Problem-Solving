"""
https://open.kattis.com/problems/costumecontest
Author: https://github.com/smh997/
"""

n = int(input())
mp = dict()
for i in range(n):
    costume = input()
    if costume not in mp:
        mp[costume] = 0
    mp[costume] += 1
min_val = min(mp.values())
ans = []
for c in mp:
    if mp[c] == min_val:
        ans.append(c)
ans.sort()
for a in ans:
    print(a)