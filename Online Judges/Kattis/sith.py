"""
https://open.kattis.com/problems/sith
Author: https://github.com/smh997/
"""
_ = input()
a = int(input())
b = int(input())
a_b = int(input())
print('JEDI' if a_b < 0 else 'VEIT EKKI' if a-b >= 0 else 'SITH')