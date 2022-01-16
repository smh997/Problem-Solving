"""
https://open.kattis.com/problems/sumkindofproblem
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    d, n = map(int, input().split())
    print(d, n*(n+1)//2, n*n, n*(n+1))