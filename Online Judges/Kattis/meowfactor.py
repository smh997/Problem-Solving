"""
https://open.kattis.com/problems/meowfactor
Author: https://github.com/smh997/
"""
n = int(input())
for i in reversed(range(130)):
    if n % (i**9) == 0:
        print(i)
        break
