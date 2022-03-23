"""
https://quera.org/problemset/9110/
Author: https://github.com/smh997/
"""
import math
l, r = map(int,input().split())
s = "1"
d = ""
for i in range(int(math.ceil(math.log2(r)))):
    d = ""
    for char in s:
        if char == '0':
            d += "1"
        else:
            d += "0"
    s += d
print(s[l - 1:r])
