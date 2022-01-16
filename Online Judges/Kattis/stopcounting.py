"""
https://open.kattis.com/problems/stopcounting
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
res = [li[0]]
res2 = [li[n-1]]
for i in range(1, n):
    res.append(res[i-1] + li[i])
    res2.append(res2[i-1] + li[n-i-1])
best = 0
for i in range(n):
    best = max(best, max((res[i]) / (i+1), (res2[n - i - 1])/(n - i)))
print(best)