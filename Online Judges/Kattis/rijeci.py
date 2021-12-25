"""
https://open.kattis.com/problems/rijeci
Author: https://github.com/smh997/
"""
k = int(input())
ca, cb = 1, 0
for i in range(k):
    a, b = cb, cb + ca
    ca, cb = a, b
print(ca, cb)