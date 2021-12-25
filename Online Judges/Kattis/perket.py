"""
https://open.kattis.com/problems/perket
Author: https://github.com/smh997/
"""
def mul(a, li):
    res = 1
    for j in range(len(li)):
        if ((1 << j) & a) != 0:
            res *= li[j][0]
    return res


def sum2(a, li):
    res = 0
    for j in range(len(li)):
        if ((1 << j) & a) != 0:
            res += li[j][1]
    return res


n = int(input())
li = []
for i in range(n):
    s, b = map(int, input().split())
    li.append((s, b))
m = 1e9
for i in range(1, 1 << n):
    m = min(m, abs(mul(i, li) - sum2(i, li)))
print(m)
