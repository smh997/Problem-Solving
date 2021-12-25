"""
https://open.kattis.com/problems/primaryarithmetic
Author: https://github.com/smh997/
"""
while True:
    a, b = map(str, input().split())
    if a == '0' and b == '0':
        break
    if len(a) > len(b):
        b = '0'*(len(a)-len(b)) + b
    elif len(a) < len(b):
        a = '0' * (len(b) - len(a)) + a
    res = 0
    carr = 0
    for i in reversed(range(len(a))):
        carr = (int(a[i]) + int(b[i]) + carr) // 10
        res += 1 if carr else 0
    print(res if res else 'NO', end=' ')
    print('carry operation', end='')
    print('s.' if res > 1 else '.')
