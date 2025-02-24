"""
https://open.kattis.com/problems/ginfizz
Author: https://github.com/smh997/
"""

x = int(input())
print(f'{45 * x} ml gin')
print(f'{30 * x} ml fresh lemon juice')
print(f'{10 * x} ml simple syrup')
print(f'{x} slice of lemon' if x == 1 else f'{x} slices of lemon')
