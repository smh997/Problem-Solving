"""
https://codeforces.com/contest/1457/problem/A
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    n, m, r, c = map(int, input().split())
    print(max(max(r-1+c-1, n-r+m-c), max(n-r+c-1, m-c+r-1)))