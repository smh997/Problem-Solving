"""
https://open.kattis.com/problems/divvyingup
Author: https://github.com/smh997/
"""

input()
print('no' if sum(list(map(int, input().split()))) % 3 else 'yes')