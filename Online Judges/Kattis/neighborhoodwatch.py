"""
https://open.kattis.com/problems/neighborhoodwatch
Author: https://github.com/smh997/
"""
n, k = map(int, input().split())
li = [0] + [int(input()) for i in range(k)] + [n+1]
res = 0
for i in range(1, k+2):
    s = li[i] - li[i-1] - 1
    res += (s * (s-1) // 2) + s
print((n * (n-1) // 2) + n - res)