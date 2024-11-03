"""
https://open.kattis.com/problems/millifaersla
Author: https://github.com/smh997/
"""

li = [int(input()) for _ in range(3)]
m = min(li)
print('Monnei' if li[0] == m else 'Fjee' if li[1] == m else 'Dolladollabilljoll')