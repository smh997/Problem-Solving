"""
https://open.kattis.com/problems/jumbojavelin
Author: https://github.com/smh997/
"""
n = int(input())
s = sum([int(input()) for i in range(n)])
print(s-n+1)