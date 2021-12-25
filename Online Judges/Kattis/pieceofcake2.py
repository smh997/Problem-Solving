"""
https://open.kattis.com/problems/pieceofcake2
Author: https://github.com/smh997/
"""
n, h, v = map(int, input().split())
print(max(h, n-h)*max(v, n-v)*4)