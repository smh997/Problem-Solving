"""
https://open.kattis.com/problems/grassseed
Author: https://github.com/smh997/
"""
c = float(input())
n = int(input())
s = 0
for i in range(n):
    W, L = map(float, input().split())
    s += W * L
print("%.6f" % (s * c))
