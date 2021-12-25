"""
https://open.kattis.com/problems/numberfun
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    a, b, c = map(int, input().split())
    print('Possible' if a + b == c or a * b == c or a / b == c or b / a == c or a - b == c or b - a == c else 'Impossible')
