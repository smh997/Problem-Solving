"""
https://open.kattis.com/problems/meddelande
Author: https://github.com/smh997/
"""

n, m = map(int, input().split())
print(''.join([''.join(input().split('.')) for i in range(n)]))