"""
https://open.kattis.com/problems/climbingstairs
Author: https://github.com/smh997/
"""
n, r, k = map(int, input().split())
if r >= k:
    if n-r >= 0:
        print(r + (n-r) + (n-r) % 2 + r)
    else:
        print(2*r)
else:
    if n-k - (k-r) >= 0:
        print(k + (k-r) + (n-k-(k-r)) + (n - k - (k-r)) % 2 + r)
    else:
        print(2*k)