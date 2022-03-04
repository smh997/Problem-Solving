"""
https://quera.org/problemset/44080/
Author: https://github.com/smh997/
"""
n, x = map(int, input().split())
li = list(map(int, input().split()))
li.sort()
for i in range(1, n):
    if li[i] + li[i - 1] > x:
        print(i)
        exit(0)
print(n)