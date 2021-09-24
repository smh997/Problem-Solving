"""
https://open.kattis.com/problems/chanukah
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    k, n = map(int, input().split())
    print(k, n + (n * (n+1))//2)