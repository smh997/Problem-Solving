"""
https://quera.org/problemset/3432/
Author: https://github.com/smh997/
"""
n, m = map(int, input().split())
mj = set(map(int, input().split()))
mf = set(map(int, input().split()))
if len(mj ^ mf) == 0:
    print('Both')
elif len(mj - mf) == 0:
    print('Mohammad Javad')
elif len(mf - mj) == 0:
    print('Mostafa')
else:
    print('None')
