"""
https://open.kattis.com/problems/checkingforcorrectness
Author: https://github.com/smh997/
"""
import sys

lines = sys.stdin.readlines()
for line in lines:    
    a, c, b = map(str, line.split())
    a, b = int(a), int(b)
    if c == '+':
        print((a+b) % 10000)
    elif c == '*':
        print((a*b) % 10000)
    else:
        print(pow(a, b, 10000))
