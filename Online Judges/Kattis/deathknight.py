"""
https://open.kattis.com/problems/deathknight
Author: https://github.com/smh997/
"""
n, res = int(input()), 0
for i in range(n):
    if 'CD' not in input():
        res += 1
print(res)