"""
https://open.kattis.com/problems/lostlineup
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
res = [0 for i in range(n)]
res[0] = 1
for i in range(len(li)):
    res[li[i]+1] = i+2
for i in range(n):
    print(res[i], end=' ')
print()