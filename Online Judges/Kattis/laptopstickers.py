"""
https://open.kattis.com/problems/laptopstickers
Author: https://github.com/smh997/
"""

L, H, K = map(int, input().split())
li = [['_' for j in range(L)] for i in range(H)]
for k in range(K):
    l, h, a, b = map(int, input().split())
    for i in range(h):
        for j in range(l):
            if i + b < H and j + a < L:
                li[i+b][j+a] = chr(ord('a') + k)
            else:
                break
for i in range(H):
    print(''.join(li[i]))