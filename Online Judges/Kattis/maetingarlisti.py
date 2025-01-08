"""
https://open.kattis.com/problems/Mætingarlisti
Author: https://github.com/smh997/
"""

n, r, c = map(int, input().split())
rows = []
for i in range(r):
    row = input().split()
    rows.append(row)
for i in range(r):
    r = []
    for j in range(c):
        r.append(input())
    print('left' if rows[i] == r else 'right')
