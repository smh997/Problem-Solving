"""
https://open.kattis.com/problems/ofugsnuid
Author: https://github.com/smh997/
"""

n = int(input())
li = [input() for _ in range(n)]
print('\n'.join(li[::-1]))