"""
https://open.kattis.com/problems/einfalt
Author: https://github.com/smh997/
"""

def fact(i):
    if i == 0:
        return 1
    return i * fact(i-1)
print(fact(int(input())))