"""
https://open.kattis.com/problems/stickykeys
Author: https://github.com/smh997/
"""

s = input()
print(''.join([s[0]]+[s[i] for i in range(1, len(s)) if s[i] != s[i-1]]))
