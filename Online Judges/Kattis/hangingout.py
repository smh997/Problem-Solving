"""
https://open.kattis.com/problems/hangingout
Author: https://github.com/smh997/
"""
n, m = map(int, input().split())
s = 0
res = 0
for i in range(m):
    w, L = input().split()
    L = int(L)
    if w == 'enter':
        if s + L > n:
            res += 1
        else:
            s += L
    else:
        s -= L
print(res)
