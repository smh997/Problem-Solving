"""
https://open.kattis.com/problems/bladra
Author: https://github.com/smh997/
"""

k, q = map(int, input().split())
li = [0 for i in range(k)]
for _ in range(q):
    _, b = map(int, input().split())
    li[b-1] += 1
print(min(li))