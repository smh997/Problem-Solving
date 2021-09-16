"""
https://open.kattis.com/problems/brokencalculator
Author: https://github.com/smh997/
"""
n = int(input())
pre = 1
for i in range(n):
    a, op, b = map(str, input().split())
    a = int(a)
    b = int(b)
    if op == '+':
        pre = a + b - pre
        print(pre)
    elif op == '-':
        pre = (a - b) * pre
        print(pre)
    elif op == '*':
        pre = (a * b) ** 2
        print(pre)
    elif op == '/':
        if a % 2:
            pre = (a + 1) // 2
        else:
            pre = a // 2
        print(pre)

