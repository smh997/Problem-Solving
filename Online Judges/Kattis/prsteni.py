"""
https://open.kattis.com/problems/prsteni
Author: https://github.com/smh997/
"""
import math
n = int(input())
li = list(map(int, input().split()))
aa, bb = 1, 1
for i in range(1, n):
    g = math.gcd(li[i-1]*aa, li[i]*bb)
    a = li[i-1]*aa//g
    b = li[i]*bb//g
    aa, bb = a, b
    print('%d/%d' % (a, b))
