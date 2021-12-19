"""
https://open.kattis.com/problems/gerrymandering
Author: https://github.com/smh997/
"""
p, D = map(int, input().split())
A = [0]*D
B = [0]*D
wa = 0
wb = 0
s = 0
while p:
    p -= 1
    d, a, b = map(int, input().split())
    A[d-1] += a
    B[d-1] += b
    s += a + b
for i in range(D):
    w = (A[i] + B[i]) // 2 + 1
    if A[i] > B[i]:
        wa += A[i] - w
        wb += B[i]
        print('A', A[i] - w, B[i])
    else:
        wa += A[i]
        wb += B[i] - w;
        print('B', A[i], B[i] - w)
print(abs(wa - wb) / s)
