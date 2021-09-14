"""
https://open.kattis.com/problems/listgame
Author: https://github.com/smh997/
"""
n = int(input())
res = 0
for i in range(2, int(n ** 0.5)+1):
    while not n % i:
        n //= i
        res += 1
    if n==1:
        break
if n>2:
    res += 1
print(res)