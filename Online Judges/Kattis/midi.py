"""
https://open.kattis.com/problems/midi
Author: https://github.com/smh997/
"""

n = int(input())
print(''.join([input()[::-1] for _ in range(n)][::-1]))