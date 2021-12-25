"""
https://open.kattis.com/problems/ratingproblems
Author: https://github.com/smh997/
"""
n, k = map(int, input().split())
s = 0
for i in range(k):
    a = int(input())
    s += a
print((s+(n-k)*(-3))/n, (s+(n-k)*3)/n)
