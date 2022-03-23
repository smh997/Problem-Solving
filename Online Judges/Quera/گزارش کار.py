"""
https://quera.org/problemset/49535/
Author: https://github.com/smh997/
"""
n, k = map(int, input().split())
print('YES' if sum([int(input()) for i in range(n)]) >= k else 'NO')