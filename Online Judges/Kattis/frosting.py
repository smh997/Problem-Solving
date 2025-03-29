"""
https://open.kattis.com/problems/frosting
Author: https://github.com/smh997/
"""

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
W = [0 for _ in range(3)]

res = [0 for _ in range(3)]

for i in range(n):
    W[i % 3] += A[i]

for i in range(n):
    for j in range(3):
        res[j] += W[(i + 1 + j + (i % 3)) % 3] * B[i]
print(*res, sep=" ")
    