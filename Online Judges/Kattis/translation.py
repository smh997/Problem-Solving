"""
https://open.kattis.com/problems/translation
Author: https://github.com/smh997/
"""

n = int(input())
orig = input().split()
m = int(input())
di = dict()
for i in range(m):
    a, b = map(str, input().split())
    di[a] = b
print(' '.join([di[a] for a in orig]))