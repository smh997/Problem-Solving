"""
https://open.kattis.com/problems/nered
Author: https://github.com/smh997/
"""
n, m = map(int, input().split())
plain = [[1 for i in range(n)] for j in range(n)]
for i in range(m):
    r, c = map(int, input().split())
    plain[r-1][c-1] = 0
ps = [[0 for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(n):
        ps[i][j] = plain[i][j] + (ps[i-1][j] if i > 0 and j>=0 else 0) + (ps[i][j-1] if i >= 0 and j>0 else 0) - (ps[i-1][j-1] if i > 0 and j>0 else 0)
res = int(1e9)
for i in range(n):
    for j in range(n):
        for k in range(i, n):
            for l in range(j, n):
                if (k-i+1) * (l-j+1) == m:
                    res = min(res, ps[k][l] - (ps[i-1][l] if i>0 and l>=0 else 0) - (ps[k][j-1] if j>0 and k>=0 else 0) + (ps[i-1][j-1] if i>0 and j>0 else 0))
print(res)