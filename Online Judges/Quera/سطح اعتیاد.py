"""
https://quera.org/problemset/2887/
Author: https://github.com/smh997/
"""
import math
n = int(input())
li = list(map(int, input().split()))
g = li[0]
for mem in li:
    g = math.gcd(g, mem)
print(sum(li) // g)
