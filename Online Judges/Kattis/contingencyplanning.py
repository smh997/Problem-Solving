"""
https://open.kattis.com/problems/contingencyplanning
Author: https://github.com/smh997/
"""

n = int(input())+1
if n > 12:
    print('JUST RUN!!')
    exit(0)

fact = [1] * n
for i in range(2, n):
    fact[i] = fact[i-1] * i
C = [[]] * n
for i in range(n):
    C[i] = ([0] * n).copy()
C[0][0] = 1
for i in range(1, n):
    C[i][0] = 1
    for j in range(1, i+1):
        C[i][j] = C[i-1][j] + C[i-1][j-1]
ans = 0
for i in range(1, n):
    ans += C[n-1][i] * fact[i]
print(ans)