"""
https://open.kattis.com/problems/tornbygge
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
res = 1
for i in range(1, len(li)):
    if li[i] > li[i-1]:
        res += 1
print(res)