"""
https://open.kattis.com/problems/sifferprodukt
Author: https://github.com/smh997/
"""
x = int(input())
while x >= 10:
    a = 1
    for d in str(x):
        if d == '0':
            continue
        a *= int(d)
    x = a
print(x)