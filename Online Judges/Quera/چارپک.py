"""
https://quera.org/problemset/31022/
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
c = li.count(3)
b = li.count(2)
a = li.count(1)
it = 0
while a != 0 or b != 0 or c != 0:
    it += 1
    tmp = 4
    tmpb = 0
    tmpa = 0
    if tmp >= c:
        tmp -= c
        tmpb += c
        c = 0
    else:
        tmpb += tmp
        c -= tmp
        tmp = 0
    if tmp >= b:
        tmp -= b
        tmpa += b
        b = 0
    else:
        tmpa += tmp
        b -= tmp
        tmp = 0
    if tmp >= a:
        tmp -= a
        a = 0
    else:
        a -= tmp
        tmp = 0
    b += tmpb
    a += tmpa
print(it)
