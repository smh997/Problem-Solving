"""
https://quera.org/problemset/41175/
Author: https://github.com/smh997/
"""
g = sum(list(map(int, input().split())))
e = sum(list(map(int, input().split())))
print('Tie' if g == e else 'Emma' if g < e else 'Gunnar')