"""
https://quera.org/problemset/35253/
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
m = max(li)
for i in range(n):
    if li[i] == m:
        print(i + 1)
