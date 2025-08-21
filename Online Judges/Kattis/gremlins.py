"""
Author https://github.com/smh997/
https://open.kattis.com/problems/gremlins
"""

n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]
mp = dict()
for i in range(m):
    mp[b[i]] = i + 1
for i in range(n):
    if a[i] in mp:
        print(mp[a[i]])
    else:
        print('stolen!')
