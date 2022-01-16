"""
https://open.kattis.com/problems/threedigits
Author: https://github.com/smh997/
"""
n = int(input())
res = 1
tw, fi = 0, 0
for i in range(2, n+1):
    x = i
    while not x % 2:
        x //= 2
        tw += 1
    while not x % 5:
        x //= 5
        fi += 1
    res = (res * x) % 1000
for i in range(tw - fi):
    res = (res * 2) % 1000
if n > 6:
    print('%03d' % (res % 1000))
else:
    print(res)