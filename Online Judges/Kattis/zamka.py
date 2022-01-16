"""
https://open.kattis.com/problems/zamka
Author: https://github.com/smh997/
"""
L = int(input())
D = int(input())
X = int(input())
for i in range(L, D+1):
    if sum([int(a) for a in str(i)]) == X:
        print(i)
        break
for i in range(D, L-1, -1):
    if sum([int(a) for a in str(i)]) == X:
        print(i)
        break
