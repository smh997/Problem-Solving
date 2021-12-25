"""
https://open.kattis.com/problems/quiteaproblem
Author: https://github.com/smh997/
"""
import sys

lines = sys.stdin.readlines()
for s in lines:
    s = s.lower()
    print('yes' if 'problem' in s else 'no')