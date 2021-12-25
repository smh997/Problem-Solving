"""
https://open.kattis.com/problems/loworderzeros
Author: https://github.com/smh997/
"""
li = [0] * 1000001
fac = 1
for i in range(1, 1000001):
    fac *= i
    while not fac % 10:
        fac //= 10
    li[i] = fac % 10
    fac %= 1000000
while True:
    n = int(input())
    if not n:
        break
    print(li[n])
