"""
https://open.kattis.com/problems/krizaljka
Author: https://github.com/smh997/
"""
a, b = map(str, input().split())
i, j = 0, 0
for ii, aa in enumerate(a):
    if aa in b:
        i = b.index(aa)
        j = ii
        break
n, m = len(a), len(b)
for ii in range(m):
    for jj in range(n):
        if ii == i:
            print(a[jj], end='')
        elif jj == j:
            print(b[ii], end='')
        else:
            print('.', end='')
    print()
