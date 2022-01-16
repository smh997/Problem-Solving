"""
https://open.kattis.com/problems/stararrangements
Author: https://github.com/smh997/
"""
n = int(input())
print('%d:' % n)
for i in range(2, (n+1)//2+1):
    if n % (2 * i -1) in [0, i]:
        print('%d,%d' % (i, i-1))
    if n % (2 * i) in [0, i]:
        print('%d,%d' % (i, i))
