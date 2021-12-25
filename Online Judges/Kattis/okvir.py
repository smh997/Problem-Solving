"""
https://open.kattis.com/problems/okvir
Author: https://github.com/smh997/
"""
m, n = map(int, input().split())
u, l, r, d = map(int, input().split())
words = []
for i in range(m):
    words.append(input())
k = 0
for i in range(u):
    for j in range(l+n+r):
        print('.' if (j+k) % 2 else '#', end='')
    print()
    k += 1
for i in range(m):
    for j in range(l):
        print('.' if (j + k) % 2 else '#', end='')
    print(words[i], end='')
    for j in range(l+n, l+r+n):
        print('.' if (j + k) % 2 else '#', end='')
    print()
    k += 1
for i in range(d):
    for j in range(l+n+r):
        print('.' if (j+k) % 2 else '#', end='')
    print()
    k += 1
