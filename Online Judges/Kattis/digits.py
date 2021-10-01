"""
https://open.kattis.com/problems/digits
Author: https://github.com/smh997/
"""
while True:
    s = input()
    if s == 'END':
        break
    x = str(len(s))
    i = 1
    while s != x:
        s = x
        x = str(len(s))
        i += 1
    print(i)