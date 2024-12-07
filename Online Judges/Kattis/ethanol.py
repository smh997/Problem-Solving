"""
https://open.kattis.com/problems/ethanol
Author: https://github.com/smh997/
"""

n = int(input())
li = ['  H' + (n-1) * ' H', 
      '  |' + (n-1) * ' |',
      'H-C' + (n-1) * '-C' + '-OH',
      '  |' + (n-1) * ' |',
      '  H' + (n-1) * ' H']
print('\n'.join(li))