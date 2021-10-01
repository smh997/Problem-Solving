"""
https://open.kattis.com/problems/eulersnumber
Author: https://github.com/smh997/
"""
n = int(input())
fact = 1
e = 0
for i in range(n+1):
    e += 1 / fact
    fact *= i + 1
print(e)