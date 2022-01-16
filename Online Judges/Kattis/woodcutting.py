"""
https://open.kattis.com/problems/woodcutting
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    n = int(input())
    li = []
    for j in range(n):
        inp = list(map(int, input().split()))
        li.append(sum(inp[1:]))
    res = 0
    m = 0
    for j in sorted(li):
        m += j
        res += m
    print('%.06f' % (res/n))
