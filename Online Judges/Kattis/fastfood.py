"""
https://open.kattis.com/problems/fastfood
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    prizestick = []
    for j in range(n):
        li = list(map(int, input().split()))
        val = li[-1]
        prizestick.append((li[1:li[0]+1], val))
    sticks = list(map(int, input().split()))
    res = 0
    for j in range(n):
        mi = int(100000)
        for st in prizestick[j][0]:
            mi = min(sticks[st-1], mi)
        res += mi * prizestick[j][1]
    print(res)
