"""
https://open.kattis.com/problems/pauleigon
Author: https://github.com/smh997/
"""
c, p, o = map(int, input().split())
if (p+o)//c % 2:
    print("opponent")
else:
    print("paul")
