"""
https://open.kattis.com/problems/siffrid
Author: https://github.com/smh997/
"""

from math import log10

def sum_dig(a):
    ans = 0
    while a:
        ans += a % 10
        a //= 10
    return ans
n = int(input())
s = sum_dig(n)
d = int(log10(n))
mi = 10 ** d
x = s - 1
y = 1
for i in range(d):
    if x > 10:
        mi += 9 * y 
        x -= 9
    else:
        mi += y * x
        x = 0
    y *= 10
mi += x * y
mx = 0
x = s
y = 10 ** d
for i in range(d):
    if x > 10:
        mx += 9 * y 
        x -= 9
    else:
        mx += y * x
        x = 0
    y //= 10
mx += x
print(mi, mx)
