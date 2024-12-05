"""
https://open.kattis.com/problems/oddecho
Author: https://github.com/smh997/
"""

n = int(input())
for i in range(n):
    w = input()
    if i % 2 == 0:
        print(w)
