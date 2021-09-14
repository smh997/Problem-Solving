"""
https://open.kattis.com/problems/alexandbarb
Author: https://github.com/smh997/
"""
n, a, b = map(int, input().split())
print('Alex' if n % (a+b) >= a else 'Barb')