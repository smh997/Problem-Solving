"""
https://quera.org/problemset/2756/
Author: https://github.com/smh997/
"""
n = int(input())
a = 1
num2 = 0
num5 = 0
for i in range(n):
    if int(input()) == 2:
        num2 += 1
    else:
        num5 += 1
print(5, num5 + num2, -num2)
