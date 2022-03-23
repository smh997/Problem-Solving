"""
https://quera.org/problemset/108669/
Author: https://github.com/smh997/
"""
n, a, b = map(int, input().split())
li = list(map(int, input().split()))
la = -1
dovom = False
for i in range(n):
    if li[i] > la:
        la = li[i]
        if li[i] > 45 + a and not dovom:
            dovom = True
        if li[i] > 90 + b:
            print('NO')
            exit(0)
    else:
        if dovom:
            print('NO')
            exit(0)
        else:
            dovom = True
            la = li[i]
print('YES')
