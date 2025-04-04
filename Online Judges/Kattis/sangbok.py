"""
https://open.kattis.com/problems/sangbok
Author: https://github.com/smh997/
"""

t, n = map(int, input().split())
songs = sorted(list(map(int, input().split())))
tot, t = 0, t * 60
for s in songs:
    if s + tot <= t:
        tot += s
    else:
        break
print(tot)