"""
https://open.kattis.com/problems/kikiboba
Author: https://github.com/smh997/
"""

s = input()
k = s.count('k')
b = s.count('b')
print('kiki' if k > b else 'boba' if b > k else 'none' if k == b == 0 else 'boki')