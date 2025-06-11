"""
Author https://github.com/smh997/
https://open.kattis.com/problems/pakethanterare
"""

t, b = map(int, input().split())
bs = list(map(int, input().split()))
d = dict()
for i in range(t):
    name, v = map(str, input().split())
    v = int(v)
    d[name] = v
for i in range(b):
    ans = 0
    for j in range(bs[i]):
        name, v = map(str, input().split())
        v = int(v)
        ans += d[name] - v
    print(ans)
