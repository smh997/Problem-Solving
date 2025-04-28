"""
https://open.kattis.com/problems/streetsahead
Author: https://github.com/smh997/
"""

n, q = map(int, input().split())
mp = dict()
for i in range(n):
    mp[input()] = i
for i in range(q):
    a, b = map(str, input().split())
    print(abs(mp[b] - mp[a]) - 1)