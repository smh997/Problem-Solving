"""
https://open.kattis.com/problems/equalshots
Author: https://github.com/smh997/
"""

a, b = map(int, input().split())
f = lambda li : li[0] * li[1]
ansa = sum([f(list(map(int, input().split()))) for i in range(a)])
ansb = sum([f(list(map(int, input().split()))) for i in range(b)])
print('same' if ansa == ansb else 'different')