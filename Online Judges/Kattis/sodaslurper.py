"""
https://open.kattis.com/problems/sodaslurper
Author: https://github.com/smh997/
"""
a, b, c = map(int,input().split())
a += b
res = 0
while a >= c:
    res += a//c
    a = a//c + a%c
print(res)