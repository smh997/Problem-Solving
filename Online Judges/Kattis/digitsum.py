"""
https://open.kattis.com/problems/digitsum
Author: https://github.com/smh997/
"""
def s(a):
    res = 0
    while a != 0:
        res += a % 10
        a //= 10
    return res


def calc(a):
    if a <= 0:
        return 0
    if not a % 10:
        return 45 * (a//10) + 10 * calc(a//10)
    return calc(a-1) + s(a-1)


n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    print(calc(b+1)-calc(a))
