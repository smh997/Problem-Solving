"""
https://open.kattis.com/problems/eyeofsauron
Author: https://github.com/smh997/
"""

s = input()
x = s.find('()')
print('correct' if len(s) - x == x + 2 else 'fix')