"""
https://open.kattis.com/problems/pot
Author: https://github.com/smh997/
"""
n = int(input())
res = 0
for i in range(n):
    num = int(input())
    res += (num // 10) ** (num % 10)
print(res)