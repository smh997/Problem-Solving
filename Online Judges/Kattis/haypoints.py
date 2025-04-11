"""
https://open.kattis.com/problems/haypoints
Author: https://github.com/smh997/
"""

m, n = map(int, input().split())
dc = dict()
for _ in range(m):
    w, v = map(str, input().split())
    dc[w] = int(v)
for _ in range(n):
    ans = 0
    s = input()
    while s != '.':
        for word in s.split():
            if word in dc:
                ans += dc[word]
        s = input()
    print(ans)