"""
https://quera.org/problemset/108668/
Author: https://github.com/smh997/
"""
n, m, k = map(int, input().split())
li = [[0] * m for i in range(n)]
for i in range(k):
    r, c, l = map(int, input().split())
    for rr in range(r - 1, r + l - 1):
        for cc in range(c - 1, c + l - 1):
            li[rr][cc] += 1 << i
res = set()
flag = False
for i in range(n):
    for j in range(m):
        if li[i][j] == 0:
            flag = True
        res.add(li[i][j])
if flag:
    res.remove(0)
print(len(res))
