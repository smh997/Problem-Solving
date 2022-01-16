"""
https://open.kattis.com/problems/somesum
Author: https://github.com/smh997/
"""
n = int(input())
print('Either' if n % 2 else 'Odd' if (n // 2) % 2 else 'Even')