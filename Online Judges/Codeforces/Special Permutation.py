"""
https://codeforces.com/contest/1454/problem/A
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    n = int(input())
    for j in range(2, n+1):
        print(j, end=' ')
    print(1)