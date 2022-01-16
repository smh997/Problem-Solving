"""
https://open.kattis.com/problems/temperatureconfusion
Author: https://github.com/smh997/
"""
from fractions import Fraction

a, b = map(int, input().split('/'))
f = Fraction(a, b)
ans = (f - Fraction(32, 1)) * Fraction(5, 9)
print(f'{ans.numerator}/{ans.denominator}')