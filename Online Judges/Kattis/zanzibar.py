"""
https://open.kattis.com/problems/zanzibar
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    li = list(map(int, input().split()))
    s = 0
    for j in range(1, len(li)):
        if li[j] > li[j-1] * 2:
            s += li[j] - li[j-1] * 2
    print(s)
