"""
https://open.kattis.com/problems/qaly
Author: https://github.com/smh997/
"""
n = int(input())
res = 0
for i in range(n):
    a, b = map(float, input().split())
    res += a * b
print("%.03f" % res)
