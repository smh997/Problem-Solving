"""
Author https://github.com/smh997/
https://open.kattis.com/problems/wakeupcall
"""

n, m = map(int, input().split())
a = sum(list(map(int, input().split())))
b = sum(list(map(int, input().split())))
print('Button 1' if a > b else 'Button 2' if a < b else 'Oh no')
