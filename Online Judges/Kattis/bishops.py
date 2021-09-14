"""
https://open.kattis.com/problems/bishops
Author: https://github.com/smh997/
"""
import sys

lines = sys.stdin.readlines()
for line in lines:
    n = int(line)
    print(2*n-2 if n > 1 else 1)
