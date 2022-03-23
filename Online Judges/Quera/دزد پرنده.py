"""
https://quera.org/problemset/2795/
Author: https://github.com/smh997/
"""
t = int(input())
p = []
for i in range(t):
    res = 'Yes'
    n, k = map(int, input().split())
    li = [[0, 0] for ii in range(n)]
    p.clear()
    for j in range(k):
        f, w = map(int, input().split())
        li[f - 1][w] = 1
        p.append((f - 1, w))
    for a in p:
        if li[a[0] + 1][not a[1]] == 1:
            res = 'No'
            break
    print(res)
