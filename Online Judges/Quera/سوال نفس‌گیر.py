"""
https://quera.org/problemset/26651/
Author: https://github.com/smh997/
"""
n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
sum = 0
for i in range(n):
    sum += a[i] * b[i]
print(sum)
