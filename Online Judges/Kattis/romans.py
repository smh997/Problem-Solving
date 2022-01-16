"""
https://open.kattis.com/problems/romans
Author: https://github.com/smh997/
"""
a = float(input()) * 1000 * 5280 / 4854
print(round(a if a * 10 % 10 != 0.5 else a + 0.1))
