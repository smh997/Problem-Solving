"""
https://open.kattis.com/problems/tarifa
Author: https://github.com/smh997/
"""
x = int(input())
n = int(input())
sum = 0
for i in range(n):
    sum = (sum+x) - int(input())
sum += x
print(sum)