"""
https://open.kattis.com/problems/sumsquareddigits
Author: https://github.com/smh997/
"""
m = int(input())
for i in range(m):
    res = 0
    k, b, n = map(int, input().split())
    while n:
        res += (n % b) ** 2
        n //= b
    print(k, res)
