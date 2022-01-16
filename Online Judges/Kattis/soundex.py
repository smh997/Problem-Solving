"""
https://open.kattis.com/problems/soundex
Author: https://github.com/smh997/
"""
import sys


di = {'B': 1, 'F': 1, 'P': 1, 'V': 1, 'C': 2, 'G': 2, 'J': 2, 'K': 2, 'Q': 2, 'S': 2, 'X': 2, 'Z': 2, 'D': 3, 'T': 3, 'L': 4, 'M': 5, 'N': 5, 'R': 6}
lines = sys.stdin.readlines()
for s in lines:
    ss = ''
    par = -1
    for i in range(len(s)):
        if s[i] not in di:
            par = -1
        elif par == -1:
            par = di[s[i]]
            ss += str(di[s[i]])
        elif di[s[i]] != par:
            par = di[s[i]]
            ss += str(di[s[i]])
    print(ss)
