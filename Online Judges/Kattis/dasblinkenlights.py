"""
https://open.kattis.com/problems/dasblinkenlights
Author: https://github.com/smh997/
"""
import math
a, b, s = map(int, input().split())
print('yes' if a * b // math.gcd(a, b) <= s else 'no')
