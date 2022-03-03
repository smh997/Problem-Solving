"""
https://open.kattis.com/problems/bestcompression
Author: https://github.com/smh997/
"""
n, b = map(int, input().split())
print('yes' if n <= ((1 << (b+1)) - 1) else 'no')
