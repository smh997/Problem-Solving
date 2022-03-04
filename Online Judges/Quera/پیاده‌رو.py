"""
https://quera.org/problemset/104590/
Author: https://github.com/smh997/
"""
n, q = map(int, input().split())
li = list(map(int, input().split()))
r = [i for i in range(n)]
l = [i for i in range(n)]
for i in range(1, n):
    if li[i] != li[i - 1]:
        r[i] = r[i - 1]
for i in reversed(range(0, n - 1)):
    if li[i] != li[i + 1]:
        l[i] = l[i + 1]
for i in range(q):
    s, e = map(int, input().split())
    s -= 1
    e -= 1
    if s < e:
        if r[e] <= s:
            print('YES')
        else:
            print('NO')
    else:
        if l[e] >= s:
            print('YES')
        else:
            print('NO')
