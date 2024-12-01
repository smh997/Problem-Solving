"""
https://open.kattis.com/problems/zoom
Author: https://github.com/smh997/
"""

n, k = map(int, input().split())
li = list(map(int, input().split()))
print(' '.join([str(li[j]) for j in range(k-1, n, k)]))