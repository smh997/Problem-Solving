"""
https://open.kattis.com/problems/bottleopening
Author: https://github.com/smh997/
"""

n = int(input())
k = int(input())
print('impossible' if k >= n else '\n'.join([f'open {i} using {i+1}' for i in range(1, k+1)]))
