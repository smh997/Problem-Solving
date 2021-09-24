"""
https://open.kattis.com/problems/creditcard
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    r, b, m = map(float, input().split())
    r = r
    b = b*100
    m = m*100
    cnt = 0
    while cnt + 1 <= 1200:
        if abs(b) < 1e-9:
            break
        interest = int(round(r*b/100))
        b += interest
        b = b - min(b, m)
        cnt += 1
    if abs(b) < 1e-9:
        print(cnt)
    else:
        print('impossible')
