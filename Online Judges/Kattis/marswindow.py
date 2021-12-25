"""
https://open.kattis.com/problems/marswindow
Author: https://github.com/smh997/
"""
n = int(input())
y = 2018
m = 3
while y <= n:
    if y == n:
        print('yes')
        exit(0)
    m += 26
    y += m // 12
    m %= 12
print('no')