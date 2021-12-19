"""
https://open.kattis.com/problems/apaxianparent
Author: https://github.com/smh997/
"""
y, p = input().split()
print(y + p if y.endswith('ex') else y + 'x' + p if y.endswith('e') else y[:-1] + 'ex' + p if y.endswith('i') or y.endswith('u') or y.endswith('o') or y.endswith('a') else y + 'ex' + p)