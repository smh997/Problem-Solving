"""
https://open.kattis.com/problems/pizza2
Author: https://github.com/smh997/
"""
r, c = map(int, input().split())
print("%.06f" % ((r-c)**2 / r**2 * 100))

