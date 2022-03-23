"""
https://quera.org/problemset/33046/
Author: https://github.com/smh997/
"""
n = int(input())
li = [0 for i in range(n)]
for i in range(n - 1):
    u, v = map(int, input().split())
    li[u - 1] += 1
    li[v - 1] += 1
print(max(li))
